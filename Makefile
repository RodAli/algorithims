CC=gcc

all: bubblesort

bubblesort: bubblesort.c
	$(CC) bubblesort.c -o bubblesort 

clean: 
	rm bubblesort