/* UPTIME MODULE */
// Show uptime

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

void uptime_md(struct STATUS *status, const char *format) {
	char buffer[20] = "";
	FILE *pUptime = fopen("/proc/uptime" , "r");
	fgets(buffer, sizeof(buffer), pUptime);
	fclose(pUptime);
	char *Puptime = strtok(buffer, " ");
	long uptime = atof(Puptime);
	
	long seconds = 0, minutes = 0, hours = 0, hours_ = 0;
	
	hours = uptime / 3600;
	hours_ = uptime % 3600;
	minutes = hours_ / 60;
	seconds = hours_ % 60;

	status->uptime = realloc(status->uptime, strlen(format)+strlen(buffer));
	sprintf(status->uptime, format, seconds, minutes, hours);
}
