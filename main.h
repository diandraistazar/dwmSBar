struct STATUS {
	char *battery;
	char *volume;
	char *bright;
	char *date;
	char *uptime;
	char *memory;
	char *cpu;
};

#ifdef START
#define START
void Initialization(struct STATUS *status);
char *XSetRoot(Display *display, struct STATUS *status, int total, char ***modules, char *XSetStatus);
#endif

void battery_md(struct STATUS *status, char *format, char *path);
void volume_md(struct STATUS *status, char *format);
void bright_md(struct STATUS *status, char *format, char *path);
void date_md(struct STATUS *status, char *format);
void uptime_md(struct STATUS *status, char *format);
void memory_md(struct STATUS *status, char *format);
void cpu_md(struct STATUS *status, char *format);


