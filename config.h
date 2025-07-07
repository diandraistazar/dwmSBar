// Modules (1 for enable, 0 for disable) 
const short int modules_man[] = {
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
/*Battery*/ "%d%%",
/*Volume*/  "%d%%",
/*Bright*/  "%.lf%%",
/*Date*/    "%d-%m-%Y - %H:%M:%S",
/*Uptime*/  "%d:%d:%d",
/*memory*/  "%d MiB",
/*cpu*/     "%d%%",
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
const char *seperators[2] = { "  " , " " };
const char *path_bat      = "/sys/class/power_supply/BAT0/capacity";
const char *path_bright   = "/sys/class/backlight/amdgpu_bl1/brightness";
const int timeout         = 450;
