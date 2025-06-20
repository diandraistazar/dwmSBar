/* A simple DWM status bar written in C */

/* TODO: */
// Show current battery Capacity (DONE)
// Show current volume
// Show current brightness (DONE)
// Show current date (WORKING)
// Show current uptime (DONE)
// Show current memory Usage (DONE)
// Show current CPU usage (DONE)

// Note! some modules not working, because the modules still developing such as uptime, date, etc.
// Configuration
// Modules (1 for enable, 0 for disable)
#define BATTERY_MD	1		// Show current battery capacity
#define VOLUME_MD	1		// Show current volume
#define BRIGHT_MD	1		// Show current brightness
#define DATE_MD		1		// Show current date
#define UPTIME_MD	1		// Show system uptime
#define MEMORY_MD	1		// Show memory usage (in percentage)
#define CPU_MD		1		// Show memory usage (in percentage)

// Modules Format		Format(in string literal)
#define BAT_FORMAT		"󰂂 %d%%"						// Use %d to represent battery capacity as a decimal value
#define VOLUME_FORMAT	"󰓃 %d%%"						// Use %ld to represent volume as a long int value
#define BRIGHT_FORMAT	"󰌵 %.lf%%"						// Use %lf to represent brightness as a float value
#define MEMORY_FORMAT	"  %d MiB"						// Use %d to represent memory as a decimal value
#define CPU_FORMAT		" %d%%"						// Use %d to represent memory as a decimal value
#define UPTIME_FORMAT	"󱎫 %d:%d:%d"		// Use %d to represent uptime as a decimal value
#define DATE_FORMAT		" %d-%m-%Y - %H:%M:%S"		// Use strftime format, google it for more details

// General
#define SEP1			" < "
#define SEP2			" >"
#define PATH_BATT		"/sys/class/power_supply/BAT0/capacity"			// Battery path
#define PATH_BRIGHT		"/sys/class/backlight/amdgpu_bl1/brightness"	// Brightness path
#define TIMEOUT			450												// Delay between update status bar (in milliseconds)
#define SILENT_MODE		1												// No output if the program is running as a background process

#define START
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <signal.h>
#include "main.h"

int main() {
	// Initialization
	Display *display = XOpenDisplay(NULL);
	struct STATUS *status;
	status = (struct STATUS*)malloc(sizeof(struct STATUS));
	Initialization(status);

	// StatusBar Layout (modify as needed)
	char **modules[] = {
		&status->volume,
		&status->bright,
		&status->cpu,
		&status->memory,
		&status->battery,
		&status->date,
		&status->uptime,
	};

	int total = sizeof(modules)/sizeof(modules[0]); // total
	char *XSetStatus = NULL;

	unsigned short cond_t = 1;
	signal(SIGINT, stp_it);
	while(cond_t) {
		
		if(BATTERY_MD) { // Battery Section
			battery_md(status, BAT_FORMAT, PATH_BATT);
			if(!SILENT_MODE) printf("Battery Running...\n");
		}

		if(VOLUME_MD) { // Volume Section
			volume_md(status, VOLUME_FORMAT);
			if(!SILENT_MODE) printf("Volume Running...\n");
		}

		if(BRIGHT_MD) { // Brightness Section
			bright_md(status, BRIGHT_FORMAT, PATH_BRIGHT);
			if(!SILENT_MODE) printf("Brightness Running...\n");
		}
		
		if(MEMORY_MD) { // Memory Section
			memory_md(status, MEMORY_FORMAT);
			if(!SILENT_MODE) printf("Memory Running...\n");
		}
	
		if(UPTIME_MD) { // Uptime Section
			uptime_md(status, UPTIME_FORMAT);
			if(!SILENT_MODE) printf("Uptime Running...\n");
		}

		if(DATE_MD) { // Date Section
			date_md(status, DATE_FORMAT);
			if(!SILENT_MODE) printf("Date Running...\n");
		}

		if(CPU_MD) { // CPU Section
			cpu_md(status, CPU_FORMAT);
			if(!SILENT_MODE) printf("CPU Running...\n");
		}

		if((XSetStatus = XSetRoot(display, status, total, modules, XSetStatus)) == NULL) { // Update statusbar
			perror("Failed to connect X server: ");
			break;
		}
		usleep((TIMEOUT)*1000);
	}
	for(int x = 0; x < total; x++)
		free(*modules[x]);

	free(XSetStatus);
	free(status);
	XCloseDisplay(display);
	return 0;
}

char *XSetRoot(Display *display, struct STATUS *status, int total, char ***modules, char *XSetStatus) {
	if(display == NULL) {
		return NULL;
	}

	XSetStatus = realloc(XSetStatus, (sizeof(char)*20)*total);
	strcpy(XSetStatus, "");	
	
	for(int x = 0; x < total; x++) {
		if(*modules[x] == NULL) {
			continue;
		}
		strcat(XSetStatus, SEP1);
		strcat(XSetStatus, *modules[x]);
		strcat(XSetStatus, SEP2);
	}
	
	XStoreName(display, DefaultRootWindow(display), XSetStatus);
	XSync(display, 0);
	return XSetStatus;
}

void Initialization(struct STATUS *status) {
	status->battery = NULL;
	status->volume = NULL;
	status->bright = NULL;
	status->date = NULL;
	status->uptime = NULL;
	status->memory = NULL;
	status->cpu = NULL;
}

void stp_it(int sig) {
	printf("Received SIGINT signal\n");
	printf("dwmSBar successfully stopped...\n");
	exit(EXIT_SUCCESS);
}
