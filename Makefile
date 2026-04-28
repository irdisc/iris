CC = gcc 
PREFIX ?= /usr/local
CFLAGS = -Iinclude -I./libnet/include -I/usr/include/python3.15  -Wall
LDFLAGS = -lpython3.15
BIN_DIR = build
INSTALL_DIR = $(PREFIX)/bin
SRC = src/main.c /modules/scripts/resfinder.c
TARGET = $(BIN_DIR)/iris+ $(BIN_DIR)/resfinder

all: $(TARGET)

$(BIN_DIR)/iris+: src/main.c 
	@mkdir -p $(BIN_DIR)
	   $(CC) $^ $(LDFLAGS) -o $@ 


$(BIN_DIR)/resfinder: modules/scripts/resfinder.c libnet/libnet.c
	@mkdir -p $(BIN_DIR)
	   $(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

Install: all 
	@echo "Installing to $(INSTALL_DIR)..."
	@mkdir -p $(INSTALL_DIR)
	install -m 755 $(BIN_DIR)/iris+ $(INSTALL_DIR)/iris+
	install -m 755 $(BIN_DIR)/resfinder $(INSTALL_DIR)/resfinder


.PHONY: uninstall
uninstall:
    @echo "Removing binaries from $(INSTALL_DIR)..."
	rm -f $(TARGET)
	rm -f $(INSTALL_DIR)/iris+
	rm -f $(INSTALL_DIR)/resfinder