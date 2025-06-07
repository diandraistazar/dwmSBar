struct STATUS {
	char *battery;
	char *volume;
	char *bright;
	char *date;
	char *uptime;
	char *memory;
	char *cpu;
};

void battery_md(struct STATUS *status, char *format);
void volume_md(struct STATUS *status, char *format);
void bright_md(struct STATUS *status, char *format);
void date_md(struct STATUS *status, char *format);
void uptime_md(struct STATUS *status, char *format);
void memory_md(struct STATUS *status, char *format);
void cpu_md(struct STATUS *status, char *format);


