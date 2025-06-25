CC=clang
CFLAGS=-Wall -Wextra -Wpedantic -Werror -std=c23

SRC_DIR=src
BUILD_DIR=build

# ENTRYPOINT=$(SRC_DIR)/main.c
CFILES=$(wildcard $(SRC_DIR)/*.c)
OUTPUT=$(BUILD_DIR)/bfc

$(OUTPUT): $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CFILES) -o $(OUTPUT)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

