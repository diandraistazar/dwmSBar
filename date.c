/* DATE MODULE */
// Show current Date

#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

void date_md(struct STATUS *status, const char *format) {
	int size = strlen(format)+5;
	time_t curr_time;
	time(&curr_time);
	
	struct tm *timeinfo;
	timeinfo = localtime(&curr_time);
	status->date = realloc(status->date, size);
	strftime(status->date, size, format, timeinfo);
}
