NAME := "dwmSBar"

CC := clang
FLAGS := -Wall -lX11 -Os -I./include -DPROGRAM=\"${NAME}\"
LIBS := -lasound
SRC := src/main.c src/battery.c src/volume.c src/brightness.c src/memory.c src/cpu.c src/uptime.c src/date.c
OUT := ${NAME}

all:
	${CC} ${SRC} ${FLAGS} ${LIBS} -o ${OUT}

install:
	${CC} ${SRC} ${FLAGS} ${LIBS} -o ${OUT}
	cp ${OUT} /usr/bin

uninstall:
	rm /usr/bin/${OUT}
	rm ${OUT}
