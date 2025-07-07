/* UPTIME MODULE */
// Show uptime

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

long seconds, minutes, hours, hours_;

void uptime_md(const char *format) {
	char buffer[20] = "";
	FILE *pUptime = fopen("/proc/uptime" , "r");
	fgets(buffer, sizeof(buffer), pUptime);
	fclose(pUptime);
	char *Puptime = strtok(buffer, " ");
	long uptime = atoi(Puptime);
	
	hours = uptime / 3600;
	hours_ = uptime % 3600;
	minutes = hours_ / 60;
	seconds = hours_ % 60;

	status->uptime = realloc(status->uptime, strlen(format)+strlen(buffer));
	sprintf(status->uptime, format, seconds, minutes, hours);
}
