CC=clang

ASAN=-g -fsanitize=address
CFLAGS=-Wall -Wextra -Wpedantic -Werror -std=c23
DEBUG_CFLAGS=$(CFLAGS) $(ASAN)
RELEASE_CFLAGS=$(CFLAGS) -O3

SRC_DIR=src
BUILD_DIR=build

# ENTRYPOINT=$(SRC_DIR)/main.c
CFILES=$(wildcard $(SRC_DIR)/*.c)
HFILES=$(wildcard $(SRC_DIR)/*.h)
OUTPUT=$(BUILD_DIR)/bfc

$(OUTPUT): $(BUILD_DIR) $(CFILES) $(HFILES)
	$(CC) $(DEBUG_CFLAGS) $(CFILES) -o $(OUTPUT)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

