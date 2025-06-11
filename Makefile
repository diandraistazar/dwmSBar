CC := gcc
FLAGS := -Wall -lX11
SRC := main.c battery.c volume.c brightness.c memory.c cpu.c uptime.c date.c utils.c
OUT := dwmSBar

all:
	${CC} ${SRC} ${FLAGS} -o ${OUT}

install:
	${CC} ${SRC} ${FLAGS} -o ${OUT}
	cp ${OUT} /usr/bin

uninstall:
	rm /usr/bin/${OUT}
	rm ${OUT}
