CC=gcc

all: bubblesort quicksort

bubblesort: bubblesort.c
	$(CC) bubblesort.c -o bubblesort 

quicksort: quicksort.c
	$(CC) quicksort.c -o quicksort

clean: 
	rm bubblesort