/* MEMORY MODULE */
// Show current memory usage

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "main.h"

void memory_md(struct STATUS *status, char *format) {
	char buffer[30] = "";
	char *PmemTotal = NULL;
	char *PmemAvail = NULL;
	char *Ptemp = NULL;
	short index = 0;
	FILE *pMemory = fopen("/proc/meminfo", "r");
	
	while(fgets(buffer, sizeof(buffer), pMemory)) {
		if(index == 2) { break; }
		
		if((Ptemp = strstr(buffer, "MemTotal:"))) {
			PmemTotal = strdup(Ptemp);
			index++;
		}
		else if((Ptemp = strstr(buffer, "MemAvailable:"))) {
			PmemAvail = strdup(Ptemp);
			index++;
		}
		
		if(Ptemp == NULL) {
			free(Ptemp);
		}
	}
	
	char *start_PmemTotal = PmemTotal;
	char *start_PmemAvail = PmemAvail;
	parsingString(&PmemTotal, " ", 2);
	parsingString(&PmemAvail, " ", 2);
	long memTotal = atoi(PmemTotal);
	long memAvail = atoi(PmemAvail);
	
	int calculate = (memTotal - memAvail);
	calculate = calculate / 1049; // convert to Mebibytes
	
	status->memory = realloc(status->memory, strlen(format)+sizeof(calculate));
	sprintf(status->memory, format, calculate);

	free(start_PmemTotal);
	free(start_PmemAvail);
	
	fclose(pMemory);
}
