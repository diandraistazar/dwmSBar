/* CPU MODULE */
// Show current CPU usage

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

void cpu_md(const char *format) {
	static long prev_total, prev_idle;
	long total = 0, idle = 0;
	char buffer[64] = {0};

	FILE *p_cpu = fopen("/proc/stat", "r");
	if(!p_cpu) {
		fprintf(stderr, "'%s' cannot be opened\n", "/proc/stat");
		return;
	}
	fgets(buffer, sizeof(buffer), p_cpu);

	strtok(buffer, " ");
	for(int index = 0; index < 10; index++) {
		char *cpu_proc = strtok(NULL, " ");
		if(!cpu_proc) {
			break;
		}

		if(index == 3) {
			idle = atoi(cpu_proc);
		}
		total += atoi(cpu_proc);
	}
	
	sprintf(status.cpu, format, (float)((total-prev_total) - (idle-prev_idle)) / (float)(total-prev_total) * 100.0);
	
	prev_total = total;
	prev_idle = idle;
	fclose(p_cpu);
}
