CC=clang
CFLAGS=-Wall -Wextra -Wpedantic -Werror -std=c23

SRC_DIR=src
BUILD_DIR=build

# ENTRYPOINT=$(SRC_DIR)/main.c
CFILES=$(wildcard $(SRC_DIR)/*.c)
OUTPUT=$(BUILD_DIR)/bfc

$(OUTPUT):
	$(CC) $(CFLAGS) $(CFILES) -o $(OUTPUT)

