# This is a comment line
CC=g++
# CFLAGS will be the options passed to the compiler.
CFLAGS= -std=c++17 -Wall
all: prog
prog: main.o
	$(CC) main.o -o programa
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
clean:
	rm -rf *.o 
