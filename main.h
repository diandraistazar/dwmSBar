struct STATUS {
	char *battery;
	char *volume;
	char *bright;
	char *date;
	char *uptime;
	char *memory;
	char *cpu;
};

enum Layout {battery,volume,bright,date,uptime,memory,cpu};

#ifdef START
#define START
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <signal.h>
#include "config.h"
unsigned short cond_t;
void Init_NULL(char ***modules, int total);
short XSetRoot(int total, char ***modules);
#endif

extern struct STATUS *status;

extern const enum Layout layout[];
extern const short int modules_main[];
extern const char *mod_format[];
extern const char *seperators[2];
extern const char *path_bat;
extern const char *path_bright;
extern const int timeout;

void stp_it(int sig);
void battery_md(const char *format);
void volume_md(const char *format);
void bright_md(const char *format);
void date_md(const char *format);
void uptime_md(const char *format);
void memory_md(const char *format);
void cpu_md(const char *format);
