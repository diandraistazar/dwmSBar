# dwmSBar

![banner-github](https://github.com/diandraistazar/dwmSBar/blob/master/preview.png)

**dwmSBar** is a minimal and lightweight status bar for [dwm](https://dwm.suckless.org/), written in C. It includes several useful modules to display system information on your dwm status bar.  

## Installation
Note: To build this program, you need dependencies like ```gcc```, ```libX11```, and ```libpulse``` installed on your system.
1. Clone this repository to your local machine and navigate into the directory:
```bash
git clone https://github.com/diandraistazar/dwmSBar.git
cd dwmSBar
```
2. Build the program using ```make```, or use ```make install``` to install it to your system (requires root privileges):
```bash
make                # Build program
sudo make install   # Build program and install to your system
```
3. Run the program:
```bash
dwmSBar
```

## Configuration
Configuration is currently done in ```main.c```, specifically in the configuration section near the top of the file. Modules can be enabled or disabled by modifying the ```#define``` values:
```
// Configuration
// Modules (1 to enable, 0 to disable)
#define BATTERY_MD  1   // Show current battery capacity
#define VOLUME_MD   1   // Show current volume
#define BRIGHT_MD   1   // Show current brightness
#define DATE_MD     1   // Show current date
#define UPTIME_MD   1   // Show system uptime
#define MEMORY_MD   1   // Show memory usage (in percentage)
#define CPU_MD      1   // Show CPU usage (in percentage)
...
```
⚠️ Some modules may not work as expected because they are still under development. You are free to modify or extend them based on your needs.

## Uninstallation
To uninstall the program from your system, simply run (requires root privileges):
```
sudo make uninstall
```
