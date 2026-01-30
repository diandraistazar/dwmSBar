/* BRIGHTNESS MODULE */
// Show current brightness

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void bright_md(const char *format) {
	char buffer[4] = {0};

	FILE *p_bright = fopen(path_brightness, "r");
	if(!p_bright) {
		fprintf(stderr, PROGRAM ": '%s' cannot be opened\n", path_brightness);
		return;
	}

	int bytes = fread(buffer, sizeof(char), sizeof(buffer), p_bright);
	if(bytes > 0) {
		sprintf(status.bright, format, ((float)atoi(buffer) / 255.0) * 100.0);
	} else {
		buffer[0] = '0';
	}
	fclose(p_bright);
}
