/* BRIGHTNESS MODULE */
// Show current brightness

#include "main.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bright_md(struct STATUS *status, char *format, char *path) {
	char buffer[5] = "";
	FILE *pBright = fopen(path, "r");
	fread(buffer, 1, sizeof(buffer), pBright);
	removeNewLine(buffer);
	status->bright = realloc(status->bright, strlen(buffer)+strlen(format));
	sprintf(status->bright, format, atoi(buffer));
	fclose(pBright);
}
