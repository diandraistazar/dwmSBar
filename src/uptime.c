/* UPTIME MODULE */
// Show uptime

#include <stdio.h>
#include <sys/sysinfo.h>
#include "main.h"

void uptime_md(const char *format) {
	struct sysinfo sys_info;
	long seconds, minutes, hours, hours_;

	sysinfo(&sys_info);
	hours = sys_info.uptime / 3600;
	hours_ = sys_info.uptime % 3600;
	minutes = hours_ / 60;
	seconds = hours_ % 60;
	sprintf(status.uptime, format, seconds, minutes, hours);
}
