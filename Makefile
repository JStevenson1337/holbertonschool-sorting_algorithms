# -*- Makefile -*-


all: bubble insertion select quick print_list print_array 0-main 1-main 2-main 3-main





IDIR = ./sort.h # include directory for sort.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
CDEBUG = -g

OBJECTS = print_array.o sort.o print_list.o 0-main.o \
		1-main.o 2-main.o 3-main.o bubble_sort.o \
		selection_sort.o insertion_sort.o merge_sort.o \
		quick_sort.o shell_sort.o cocktail_sort.o \
		counting_sort.o

print_list.o: print_list.c
	$(CC) $(CFLAGS) -c print_list.c

print_arrray.o: print_list.c
	$(CC) $(CFLAGS) -c print_list.c

0-bubble_sort.o: 0-bubble_sort.c sort.h
	$(CC) $(CFLAGS) -c 0-bubble_sort.c

1-insertion_sort_list.o: 1-insertion_sort_list.c sort.h
	$(CC) $(CFLAGS) -c 1-insertion_sort_list.c

2-selection_sort.o: 2-selection_sort.c sort.h
	$(CC) $(CFLAGS) -c 2-selection_sort.c

3-quick_sort.o: 3-quick_sort.c sort.h
	$(CC) $(CFLAGS) -c 3-quick_sort.c

0-main.o: 0-main.c sort.h
	$(CC) $(CFLAGS) -c 0-main.c

1-main.o: 1-main.c sort.h
	$(CC) $(CFLAGS) -c 1-main.c

2-main.o: 2-main.c sort.h
	$(CC) $(CFLAGS) -c 2-main.c

3-main.o: 3-main.c sort.h
	$(CC) $(CFLAGS) -c 3-main.c

4-main.o: 4-main.c sort.h
	$(CC) $(CFLAGS) -c 4-main.c

print_list: print_list.o
	$(CC) $(CFLAGS) print_list.o
print_array: print_array.o
	$(CC) $(CFLAGS) print_array.o

0-main: 0-main.o
	$(CC) $(CFLAGS) 0-main.o -o 0-main
1-main: 1-main.o
	$(CC) $(CFLAGS) 1-main.o -o 1-main
2-main: 2-main.o
	$(CC) $(CFLAGS) 2-main.o -o 2-main
3-main: 4-main.o
	$(CC) $(CFLAGS) 3-main.o -o 3-main

# Final Compilation 
bubble: 0-bubble_sort.o 0-main.o print_array.o
	$(CC) $(CFLAGS) 0-bubble_sort.o 0-main.o print_array.o -o bubble
insertion: 1-insertion_sort_list.o 1-main.o print_list.o
	$(CC)  1-insertion_sort_list.o 1-main.o print_list.o -o insertion
select: 2-main.o print_array.o 2-selection_sort.o
	$(CC) $(CFLAGS) 2-main.o print_array.o 2-selection_sort.o -o select
quick: 3-main.o print_array.o 3-quick_sort.o
	$(CC) $(CFLAGS) 3-main.o print_array.o 3-quick_sort.o -o quick 

.phony: clean
clean:
	rm -f *.o bubble insertion select quick print_list print_array
