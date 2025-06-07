/* BATTERY MODULE */
// To show current battery capacity

#define PATH	"/sys/class/power_supply/BAT0/capacity"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

static void removeNewLine(char *string) {
	string[strlen(string)-1] = '\0';
}

void battery_md(struct STATUS *status, char *format) {
	char buffer[30];
	FILE *pBattery = fopen(PATH, "r");
	fread(buffer, sizeof(char), 5, pBattery);
	removeNewLine(buffer);
	sprintf(buffer, format, atoi(buffer));
	status->battery = realloc(status->battery, strlen(buffer));
	strcpy(status->battery, buffer);
	fclose(pBattery);
}
