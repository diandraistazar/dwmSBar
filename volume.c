#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "utils.h"

void volume_md(struct STATUS *status, char *format)
{
	char *command = "pactl get-sink-volume @DEFAULT_SINK@";
	char buffer[35] = "";
	char *Pbuffer = buffer;
	FILE *pOutput;

	if((pOutput = popen(command, "r")) < 0) {
		perror("Error: ");
		pclose(pOutput);
	}
	fgets(buffer, sizeof(buffer), pOutput);
	if(pOutput != NULL) {
		pclose(pOutput);
	}

	parsingString(&Pbuffer, " ", 5);
	status->volume = realloc(status->volume, strlen(format)+strlen(Pbuffer));
	sprintf(status->volume, format, atol(Pbuffer));
}
