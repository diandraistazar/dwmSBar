#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void volume_md(const char *format) {
	char buffer[4] = {0};

	FILE *p_volume = popen("pactl get-sink-volume @DEFAULT_SINK@ | head -n1 | awk '{print $5}'", "r");
	if(!p_volume) {
		fprintf(stderr, PROGRAM ": 'volume' cannot be opened\n");
		return;
	}

	fgets(buffer, sizeof(buffer), p_volume);
	sprintf(status.volume, format, atol(buffer));

	pclose(p_volume);
}
