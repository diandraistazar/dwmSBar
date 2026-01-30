/* DATE MODULE */
// Show current Date

#include <time.h>
#include "main.h"

void date_md(const char *format) {
	time_t curr_time;
	struct tm *timeinfo;
	
	time(&curr_time);
	timeinfo = localtime(&curr_time);
	strftime(status.date, LENGTH, format, timeinfo);
}
