/* CPU MODULE */
// Show current CPU usage

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "utils.h"

//void cpu_md(struct STATUS *status, char *format) {
void cpu_md(struct STATUS *status, char *format) {
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

	int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;

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

	int *addresses_int[] = {
		&user,
		&nice,
		&system,
		&idle,
		&iowait,
		&irq,
		&softirq,
		&steal,
		&guest,
		&guest_nice,
	};
	
	strtok(buffer, " ");
	for(int x = 0; x <= 9; x++) {
		addresses[x] = strtok(NULL, " ");
		*addresses_int[x] = atoi(addresses[x]);
	}

}
