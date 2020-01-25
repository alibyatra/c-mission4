# -*- Makefile -*-

all: frequency

frequency: main.o frequency.o 
	gcc -Wall -o frequency main.o frequency.o 

main.o: main.c frequency.h
	gcc -Wall -c main.c

frequency.o: frequency.c frequency.h
	gcc -Wall -c frequency.c


.PHONY: clean all 

clean:
	rm -f *.o frequency