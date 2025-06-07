CC := gcc
FLAGS := -Wall -lpthread
SRC := main.c battery.c
OUT := dwm-statusbar

all:
	${CC} ${SRC} ${FLAGS} -o ${OUT}

clean:
	rm ${OUT}
