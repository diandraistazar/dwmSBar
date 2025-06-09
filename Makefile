CC := gcc
FLAGS := -Wall -lpthread -lX11
SRC := main.c battery.c brightness.c memory.c cpu.c uptime.c utils.c
OUT := dwmSBar

all:
	${CC} ${SRC} ${FLAGS} -o ${OUT}

install:
	${CC} ${SRC} ${FLAGS} -o ${OUT}
	cp ${OUT} /usr/bin

uninstall:
	rm ${OUT}
	rm /usr/bin${OUT}
