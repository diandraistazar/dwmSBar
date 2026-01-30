/* BATTERY MODULE */
// Show current battery capacity

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

void battery_md(const char *format) {
	char buffer[4] = {0};

	FILE *p_battery = fopen(path_battery, "r");
	if(!p_battery) {
		fprintf(stderr, PROGRAM ": '%s' cannot be opened\n", path_battery);
		return;
	}

	size_t bytes = fread(buffer, sizeof(char), sizeof(buffer), p_battery);
	if(bytes > 0) {
		sprintf(status.battery, format, atoi(buffer));
	} else {
		buffer[0] = '0';
	}
	fclose(p_battery);
}
