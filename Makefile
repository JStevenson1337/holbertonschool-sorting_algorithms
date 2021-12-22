# -*- Makefile -*-

IDIR = ./sort.h 
CC = gcc
CFLAGS= -Wall -Wextra -Werror -pedantic
CDEBUG = -g

all: bubble insertion select quick print_list print_array 0-main.c


print_list: print_list.o
	$(CC) $(CFLAGS) print_list.o

print_list.o: print_list.c sort.h
	$(CC) $(CFLAGS) -c print_list.c



print_array: print_array.o
	$(CC) $(CFLAGS) print_array.o

print_arrray.o: print_list.c sort.h
	$(CC) $(CFLAGS) -c print_list.c




bubble: 0-bubble_sort.o 0-main.o print_array.o
	$(CC) $(CFLAGS) 0-bubble_sort.o 0-main.o print_array.o -o bubble

0-bubble_sort.o: 0-bubble_sort.c sort.h
	$(CC) $(CFLAGS) -c 0-bubble_sort.c
	
0-main: 0-main.o
	$(CC) $(CFLAGS) 0-main.o -o 0-main

0-main.o: 0-main.c sort.h
	$(CC) $(CFLAGS) -c 0-main.c






insertion: insertion.o
	$(CC) $(CDEBUG) insertion.o $(LDFLAGS) -o insertion

1-main: 1-main.o
	$(CC) $(CFLAGS) 1-main.o -o 1-main

1-main.o: 1-main.c sort.h
	$(CC) $(CFLAGS) -c 1-main.c


select: select.o
	$(CC) $(CDEBUG) select.o $(LDFLAGS) -o select

2-main: 2-main.o
	$(CC) $(CFLAGS) 2-main.o -o 2-main

2-main.o: 2-main.c sort.h
	$(CC) $(CFLAGS) -c 2-main.c


quick: quick.o
	$(CC) $(CDEBUG) quick.o $(LDFLAGS) -o quick

4-main: 4-main.o
	$(CC) $(CFLAGS) 4-main.o -o 4-main

4-main.o: 4-main.c sort.h
	$(CC) $(CFLAGS) -c 0-main.c




.phony: clean
clean:
	rm -f *.o bubble insertion select quick print_list print_array
