/* A simple DWM status bar written in C */

/* TODO: */
// Show current battery Capacity
// Show current volume
// Show current brightness
// Show current date 
// Show current uptime
// Show current memory Usage
// Show current CPU usage

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <signal.h>
#include "main.h"
#include "config.h"

// Global Variabels
Display *display = NULL;
STATUS status = {0};
int cond_t = 1;

char *modules[] = {
	status.battery,
	status.volume,
	status.bright,
	status.date,
	status.uptime,
	status.memory,
	status.cpu,
};
void (*function[])(const char*) = {
	battery_md,
	volume_md,
	bright_md,
	date_md,
	uptime_md,
	memory_md,
	cpu_md,
};

// Function prototypes
void stop(int sig);
void Initialize_NULL();
void update_modules();
void update_bar();

int main() {
	display = XOpenDisplay(NULL);
	if(!display) {
		fprintf(stderr, PROGRAM ": cannot open X11 display\n");
		return 1;
	}
	Initialize_NULL();
	signal(SIGINT, stop);
	while(cond_t) {
		update_modules();	// Update modules
		update_bar(); // Update statusbar
		usleep(timeout * 1000);
	}
	XCloseDisplay(display);
	fprintf(stdout, PROGRAM ": program terminated\n");
	return 0;
}

void update_modules() {
	for(int index = 0; index < COUNT; index++) {
		if(enable_modules[index]) {
			function[index](mod_format[index]);
		}
	}
}

void update_bar() {
	char buffer[BUFFER_SIZE] = {0};
	
	for(int index = 0; index < COUNT; index++) {
		if(enable_modules[index]) {
			strcat(buffer, seperators[0]);
			strcat(buffer, modules[layout[index]]);
			strcat(buffer, seperators[1]);
		}
	}

	XStoreName(display, DefaultRootWindow(display), buffer);
	XSync(display, 0);
}

void Initialize_NULL() {
	for(int i = 0; i < COUNT; i++) {
		memset(modules[i], 0, LENGTH);
	}
}

void stop(int sig) {
	fprintf(stdout, PROGRAM ": Received SIGINT signal\n");
	cond_t = 0;
}
