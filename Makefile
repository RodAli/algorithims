CC = gcc
CFLAGS = -Wall -Wextra -O2

SRC_DIR = src
OUT_DIR = out

SRC = $(wildcard $(SRC_DIR)/*.c)
OUT = $(patsubst $(SRC_DIR)/%.c, $(OUT_DIR)/%, $(SRC))

all: $(OUT)

$(OUT_DIR)/%: $(SRC_DIR)/%.c | $(OUT_DIR)
	$(CC) $(CFLAGS) -o $@ $<

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

clean:
	rm -rf $(OUT_DIR)

.PHONY: all clean
