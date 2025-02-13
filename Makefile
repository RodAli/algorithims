CC = gcc
CFLAGS = -Wall -Wextra -O2

SRC = $(wildcard *.c)

OUT = $(SRC:.c=)

all: $(OUT)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(OUT)

.PHONY: all clean
