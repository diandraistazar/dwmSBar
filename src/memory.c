/* MEMORY MODULE */
// Show current memory usage

#include <stdio.h>
#include <sys/sysinfo.h>
#include "main.h"

void memory_md(const char *format) {
	struct sysinfo sys_info;
	
	sysinfo(&sys_info);
	sprintf(status.memory, format, (sys_info.totalram - sys_info.freeram - sys_info.bufferram) / 1048576);
}
