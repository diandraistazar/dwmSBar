/* CPU MODULE */
// Show current CPU usage

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
#include "utils.h"

static long prev_total;
static long prev_idle;
long total;
long idle;

void cpu_md(const char *format) {
	char buffer[70] = "";
	char *cpu_proc = NULL;
	FILE *pCPU = fopen("/proc/stat", "r");
	fgets(buffer, sizeof(buffer), pCPU);
	fclose(pCPU);
	removeNewLine(buffer);

	total = 0;
	idle = 0;

	strtok(buffer, " ");
	for(int x = 0; x <= 9; x++) {
		cpu_proc = strtok(NULL, " ");
		total += atoi(cpu_proc);
		if(x == 3) {
			idle = atoi(cpu_proc);
		}
	}
	
	int cpu = 100 - ((idle-prev_idle) * 100) / (total-prev_total);

	prev_total = total;
	prev_idle = idle;
	
	status->cpu = realloc(status->cpu, strlen(format)+4);
	sprintf(status->cpu, format, cpu);
}
