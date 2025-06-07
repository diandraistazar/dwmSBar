/* A SIMPLE DWM STATUS BAR WRITTEN IN C */

/* TODO: */
// Show Current Battery Capacity
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
#define BAT_FORMAT	"Battery is: %d%%"		// Use %d for represent battery capacity in decimal value

// General
#define SEPERATOR1	"["
#define SEPERATOR2	"]"
#define TIMEOUT		500 // in milliseconds

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

int main() {
	struct STATUS status = {
		.battery = NULL,
		.volume = NULL,
		.bright = NULL,
		.date = NULL,
		.uptime = NULL,
		.memory = NULL,
		.cpu = NULL,
	};
	while(1) {
		if(BATTERY_MD) battery_md(&status, BAT_FORMAT);
		printf("%s", status.battery);
		break;
		//usleep(TIMEOUT);
	}
	free(status.battery);
	free(status.volume);
	free(status.bright);
	free(status.date);
	free(status.uptime);
	free(status.memory);
	free(status.cpu);
	return 0;
}
