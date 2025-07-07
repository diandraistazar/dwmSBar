/* MEMORY MODULE */
// Show current memory usage

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>
#include "utils.h"
#include "main.h"

void memory_md(const char *format) {
	struct sysinfo memInfo;
	sysinfo(&memInfo);
	
	long memTotal = memInfo.totalram;
	long memAvail = memInfo.freeram;
	
	long calculate = (memTotal - memAvail);
	calculate = (calculate / 1000) / 1049; // convert to Mebibytes

	status->memory = realloc(status->memory, strlen(format)+4);
	sprintf(status->memory, format, (int)calculate);
}
