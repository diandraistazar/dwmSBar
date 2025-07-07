/* CPU MODULE */
// Show current CPU usage

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
#include "utils.h"

void cpu_md(const char *format) {
	char buffer[70] = "";
	FILE *pCPU = fopen("/proc/stat", "r");
	fgets(buffer, sizeof(buffer), pCPU);
	fclose(pCPU);
	removeNewLine(buffer);

	char *pUser = NULL;		// 2
	char *pNice = NULL;		// 3
	char *pSystem = NULL;	// 4
	char *pIdle = NULL;		// 5
	char *pIowait = NULL;	// 6
	char *pIrq = NULL;		// 7
	char *pSoftirq = NULL;	// 8
	char *pSteal = NULL;		// 9
	char *pGuest = NULL;		// 10
	char *pGuest_nice = NULL;// 11

	char *addresses[] = {
		pUser,
		pNice,
		pSystem,
		pIdle,
		pIowait,
		pIrq,
		pSoftirq,
		pSteal,
		pGuest,
		pGuest_nice,
	};

	static long prev_total = 0;
	static long prev_idle = 0;

	long total = 0;
	long idle = 0;

	strtok(buffer, " ");
	for(int x = 0; x <= 9; x++) {
		addresses[x] = strtok(NULL, " ");
		total += atoi(addresses[x]);
		if(x == 3) {
			idle = atoi(addresses[x]);
		}
	}
	
	int cpu = 100 - ((idle-prev_idle) * 100) / (total-prev_total);

	prev_total = total;
	prev_idle = idle;

	status->cpu = realloc(status->cpu, strlen(format)+4);
	sprintf(status->cpu, format, cpu);
}
