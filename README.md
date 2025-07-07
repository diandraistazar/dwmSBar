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
Configuration is currently done in ```config.h```:
```
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
...
```
You are free to modify based on your needs.

## Uninstallation
To uninstall the program from your system, simply run (requires root privileges):
```
sudo make uninstall
```
