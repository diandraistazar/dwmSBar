#pragma once

#define BUFFER_SIZE 512
#define LENGTH 100
#define COUNT 7
typedef struct {
	char battery[LENGTH];
	char volume[LENGTH];
	char bright[LENGTH];
	char date[LENGTH];
	char uptime[LENGTH];
	char memory[LENGTH];
	char cpu[LENGTH];
} STATUS;
extern STATUS status;

enum Layout {
	battery,
	volume,
	bright,
	date,
	uptime,
	memory,
	cpu
};

extern const int main_modules[];
extern const char *mod_format[];
extern const enum Layout layout[];
extern const char *seperators[2];
extern const char *path_battery;
extern const char *path_brightness;
extern const int timeout;

void battery_md(const char *format);
void volume_md(const char *format);
void bright_md(const char *format);
void date_md(const char *format);
void uptime_md(const char *format);
void memory_md(const char *format);
void cpu_md(const char *format);
