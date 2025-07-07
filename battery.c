/* BATTERY MODULE */
// Show current battery capacity

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "utils.h"

void battery_md(const char *format) {
	char buffer[5] = "";
	FILE *pBattery = fopen(path_bat, "r");
	fread(buffer, 1, sizeof(buffer), pBattery);
	fclose(pBattery);
	removeNewLine(buffer);
	status->battery = realloc(status->battery, strlen(buffer)+strlen(format));
	sprintf(status->battery, format, atoi(buffer));
}
