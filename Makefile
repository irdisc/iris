CC = gcc 
CFLAGS = -Iinclude -I./libnet/include -I/usr/include/python3.15  -Wall
LDFLAGS = -lpython3.15
BIN_DIR = /bin
SRC = src/main.c /modules/scripts/resfinder.c
TARGET = $(BIN_DIR)/iris+ $(BIN_DIR)/resfinder

all: $(TARGET)

$(BIN_DIR)/iris+: src/main.c 
	@mkdir -p $(BIN_DIR)
	   $(CC) $^ $(LDFLAGS) -o $@ 


$(BIN_DIR)/resfinder: modules/scripts/resfinder.c libnet/libnet.c
	@mkdir -p $(BIN_DIR)
	   $(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(TARGET)