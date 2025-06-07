CC := gcc
FLAGS := -Wall -lpthread -lX11
SRC := main.c battery.c
OUT := dwmSBar

all:
	${CC} ${SRC} ${FLAGS} -o ${OUT}

install:
	${CC} ${SRC} ${FLAGS} -o ${OUT}
	cp ${OUT} /usr/bin

clean:
	rm ${OUT}
	rm /usr/bin${OUT}
