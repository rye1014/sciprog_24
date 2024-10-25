CC = gcc

all: main

main: main.o matmult.o
	$(CC) -o main main.o matmult.o

main.o: main.c	
	$(CC) -c main.c

matmult.o: matmult.c 
	$(CC) -c matmult.c 

clean: 
	rm -f *.o main 