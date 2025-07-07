/* A simple DWM status bar written in C */

/* TODO: */
// Show current battery Capacity
// Show current volume
// Show current brightness
// Show current date 
// Show current uptime
// Show current memory Usage
// Show current CPU usage

#define START
#include "main.h"

int main() {
	Display *display = XOpenDisplay(NULL);
	struct STATUS *status;
	status = (struct STATUS*)malloc(sizeof(struct STATUS));
	typedef void (*ptr_func)(struct STATUS *, const char *);
	
	char **modules[] = {
		&status->battery,
		&status->volume,
		&status->bright,
		&status->date,
		&status->uptime,
		&status->memory,
		&status->cpu,
	};
	ptr_func functions[] = {
		battery_md,
		volume_md,
		bright_md,
		date_md,
		uptime_md,
		memory_md,
		cpu_md,
	};

	int total = sizeof(modules)/sizeof(functions[0]); // total
	Initialization(modules, total);
	
	signal(SIGINT, stp_it);
	cond_t = 1;
	while(cond_t) {
	
		for(int i = 0; i < total; i++) {
			(functions[i])(status, mod_format[i]);
		}
	
		if(XSetRoot(display, status, total, modules)) { // Update statusbar
			perror("Failed to connect X server: ");
			break;
		}
		usleep((timeout)*1000);
	}
	while(total--) free(*modules[total]);
	free(status);
	XCloseDisplay(display);
	printf("dwmSBar successfully stopped...\n");
	return 0;
}

short XSetRoot(Display *display, struct STATUS *status, int total, char ***modules) {
	if(display == NULL) {
		return 1;
	}
	
	char XSetStatus[120] = "";
	
	for(int x = 0; x < total; x++) {
		int index = 0;
		while(1) {
			if(layout[x] == index) {
				if(*modules[layout[x]] == NULL)
					break;
				strcat(XSetStatus, seperators[0]);
				strcat(XSetStatus, *modules[layout[x]]);
				strcat(XSetStatus, seperators[1]);
				break;
			}
			index++;
		}
	}
	XStoreName(display, DefaultRootWindow(display), XSetStatus);
	XSync(display, 0);
	return 0;
}

void Initialization(char ***modules, int total) {
	for(int i = 0; i < total; i++) {
		*modules[i] = NULL;
	}
}

void stp_it(int sig) {
	printf("\nReceived SIGINT signal\n");
	cond_t = 0;
}
