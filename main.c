/* A simple DWM status bar written in C */

/* TODO: */
// Show current battery Capacity (DONE)
// Show current volume
// Show current brightness (DONE)
// Show current date
// Show current uptime
// Show current memory Usage (DONE)
// Show current CPU usage (WORKING)

// Configuration
// Modules (1 for enable, 0 for disable)
#define BATTERY_MD	1		// Show current battery capacity
#define VOLUME_MD	1		// Show current volume
#define BRIGHT_MD	1		// Show current brightness
#define DATE_MD		1		// Show current date
#define UPTIME_MD	1		// Show system uptime
#define MEMORY_MD	1		// Show memory usage (in percentage)
#define CPU_MD		1		// Show memory usage (in percentage)

// Modules Format 
#define BAT_FORMAT		"󰂂 %d%%"		// Use %d to represent battery capacity as a decimal value
#define BRIGHT_FORMAT	"󰌵 %d%%"		// Use %d to represent volume as a decimal value
#define MEMORY_FORMAT	"  %d MiB"		// Use %d to represent memory as a decimal value
#define CPU_FORMAT		" %d%%"		// Use %d to represent memory as a decimal value

// General
#define SEP1			" / "
#define SEP2			""
#define PATH_BATT		"/sys/class/power_supply/BAT0/capacity"			// Battery path
#define PATH_BRIGHT		"/sys/class/backlight/amdgpu_bl1/brightness"	// Brightness path
#define TIMEOUT			400		// Delay between update status bar (in milliseconds)
#define SILENT_MODE		1		// No output if the program is running as a background process

#define START
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include "main.h"

int main() {
	// Initialization
	Display *display = XOpenDisplay(NULL);
	struct STATUS *status;
	status = (struct STATUS*)malloc(sizeof(struct STATUS));
	Initialization(status);

	// StatusBar Layout (modify as needed)
	char **modules[] = {
		&status->memory,
		&status->battery,
		&status->bright,
		&status->volume,
		&status->date,
		&status->uptime,
		&status->cpu,
	};

	int total;
	char *XSetStatus = NULL;
	while(1) {
		total = 0;
		
		if(BATTERY_MD) { // Battery Section
			battery_md(status, BAT_FORMAT, PATH_BATT);
			total = total + 1;
			if(!SILENT_MODE) printf("Battery Running...\n");
		}

		if(BRIGHT_MD) { // Brightness Section
			bright_md(status, BRIGHT_FORMAT, PATH_BRIGHT);
			total = total + 1;
			if(!SILENT_MODE) printf("Brightness Running...\n");
		}
		
		if(MEMORY_MD) { // Memory Section
			memory_md(status, MEMORY_FORMAT);
			total = total + 1;
			if(!SILENT_MODE) printf("Memory Running...\n");
		}
		
		if(CPU_MD) { // Memory Section
			cpu_md(status, CPU_FORMAT);
			total = total + 1;
			if(!SILENT_MODE) printf("CPU Running...\n");
		}

		if((XSetStatus = XSetRoot(display, status, total, modules, XSetStatus)) == NULL) { // Update statusbar
			perror("Gagal Terkoneksi dengan X server: ");
			break;
		}
		usleep((TIMEOUT)*1000);
	}
	free(status->battery);
	free(status->volume);
	free(status->bright);
	free(status->date);
	free(status->uptime);
	free(status->memory);
	free(status->cpu);
	free(XSetStatus);
	free(status);
	XCloseDisplay(display);
	return 0;
}

char *XSetRoot(Display *display, struct STATUS *status, int total, char ***modules, char *XSetStatus) {
	XSetStatus = realloc(XSetStatus, (sizeof(char)*20)*total);
	strcpy(XSetStatus, "");	
	
	for(int x = 0; x < total; x++) {
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
