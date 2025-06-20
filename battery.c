/* BATTERY MODULE */
// Show current battery capacity

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "utils.h"

void battery_md(struct STATUS *status, char *format, char *path) {
	char buffer[5] = "";
	FILE *pBattery = fopen(path, "r");
	fread(buffer, 1, sizeof(buffer), pBattery);
	removeNewLine(buffer);
	status->battery = realloc(status->battery, strlen(buffer)+strlen(format));
	sprintf(status->battery, format, atoi(buffer));
	fclose(pBattery);
}
