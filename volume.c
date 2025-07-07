#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "utils.h"

void volume_md(const char *format)
{
	char *command = "pactl get-sink-volume @DEFAULT_SINK@";
	char buffer[35] = "";
	char *Pbuffer = buffer;
	FILE *pOutput = popen(command, "r");
	if(!pOutput)
		return;

	fgets(buffer, sizeof(buffer), pOutput);
	parsingString(&Pbuffer, " ", 5);
	status->volume = realloc(status->volume, strlen(format)+strlen(Pbuffer));
	sprintf(status->volume, format, atol(Pbuffer));
}
