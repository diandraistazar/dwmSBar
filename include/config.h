// Modules (1 for enable, 0 for disable) 
const int enable_modules[] = {
/*Battery*/ 1,
/*Volume*/  1,
/*Bright*/  1,
/*Date*/    1,
/*Uptime*/  1,
/*memory*/  1,
/*cpu*/     1,
};

// Modules Format
const char *mod_format[] = {
/*Battery*/ "BAT:%d%%",
/*Volume*/  "VOL:%d%%",
/*Bright*/  "BRIGHT:%.lf%%",
/*Date*/    "%d-%m-%Y - %H:%M:%S",
/*Uptime*/  "%d:%d:%d",
/*memory*/  "MEM:%d MiB",
/*cpu*/     "CPU:%.1f%%",
};

// Layout
const enum Layout layout[] = {
	cpu,
	memory,
	volume,
	bright,
	battery,
	date,
	uptime,
};

// General
const char *seperators[2] = { "| " , " " };
const char *path_battery = "/sys/class/power_supply/BAT0/capacity";
const char *path_brightness = "/sys/class/backlight/amdgpu_bl0/brightness";
const int timeout = 300;
