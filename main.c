/* A SIMPLE DWM STATUS BAR WRITTEN IN C */

/* TODO: */
// Show Current Battery Capacity (DONE)
// Show Current Volume
// Show Current Brightness
// Show Current Date
// Show Current Uptime
// Show Current Memory Usage
// Show Current CPU usage

// Configuration
// Modules (1 for enable, 0 for disable)
#define BATTERY_MD	1		// To show current battery capacity
#define VOLUME_MD	1		// To show current volume
#define BRIGHT_MD	1		// To show current brightness
#define DATE_MD		1		// To show date today
#define UPTIME_MD	1		// To show Uptime
#define MEMORY_MD	1		// To show memory usage (in Persentage)
#define CPU_MD		1		// To show memory usage (in Persentage)

// Modules Format 
#define BAT_FORMAT		"Battery: %d%%"		// Use %d for represent battery capacity in decimal value
#define BRIGHT_FORMAT	"Volume: %d%%"		// Use %d for represent volume in decimal value

// General
#define SEP1			"["
#define SEP2			"]"
#define PATH_BATT		"/sys/class/power_supply/BAT0/capacity"			// Battery path
#define PATH_BRIGHT		"/sys/class/backlight/amdgpu_bl1/brightness"	// Battery path
#define TIMEOUT			500		// How long program to wait before execute next (in milliseconds) 
#define SILENT_MODE		1		// No output if the program running as background process in terminal

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include "main.h"

char *XSetRoot(struct STATUS *status, int total, char ***modules, char *XSetStatus);

int main() {
	
	// Initialization
	struct STATUS *status;
	status = (struct STATUS*)malloc(sizeof(struct STATUS));

	// Layout StatusBar (change it as your preference)
	char **modules[] = {
		&status->battery,
		&status->volume,
		&status->bright,
		&status->date,
		&status->uptime,
		&status->memory,
		&status->cpu,
	};

	int total;
	char *XSetStatus = NULL;
	while(1) {
		total = 0;
		
		if(BATTERY_MD) {
			battery_md(status, BAT_FORMAT, PATH_BATT);
			total = total + 1;
			if(SILENT_MODE) printf("Battery Running...\n");
		}

		//if(BRIGHT_MD) {
			//bright_md(status, BRIGHT_FORMAT, PATH_BRIGHT);
			//total = total + 1;
			//if(SILENT_MODE) printf("Brightness Running...\n");
		//}

		if((XSetStatus = XSetRoot(status, total, modules, XSetStatus)) == NULL) {
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
	return 0;
}

char *XSetRoot(struct STATUS *status, int total, char ***modules, char *XSetStatus) {
	XSetStatus = realloc(XSetStatus, 100);
	strcpy(XSetStatus, "");	

	for(int x = 0; x < total; x++) {
		strcat(XSetStatus, SEP1);
		strcat(XSetStatus, *modules[x]);
		strcat(XSetStatus, SEP2);
	}
	Display *display;
	if((display = XOpenDisplay(NULL)) == NULL) {
		return NULL;
	}
	XStoreName(display, DefaultRootWindow(display), XSetStatus);
	XSync(display, 0);
	XCloseDisplay(display);
	return XSetStatus;
}
