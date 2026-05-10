CC = gcc 
PREFIX ?= /usr/local
CFLAGS = -Iinclude -I./libnet/include $(PYTHON_CFLAGS)  -Wall
LDFLAGS = $(PYTHON_LDFLAGS)
BIN_DIR = build
INSTALL_DIR = $(PREFIX)/bin
SRC = src/main.c /modules/scripts/resfinder.c /modules/scripts/subdomain.c
TARGET = $(BIN_DIR)/iris+ $(BIN_DIR)/resfinder $(BIN_DIR)/subdomain
PYTHON_CONFIG := $(shell command -v python3.15-config 2> /dev/null)
all: $(TARGET)

ifeq ($(PYTHON_CONFIG),)
	@echo "Error CPython 3.15-config is not installed! please install python3.15-dev"
endif	

PYTHON_CFLAGS := $(shell $(PYTHON_CONFIG) --include)
PYTHON_LDFLAGS := $(shell $(PYTHON_CONFIG) --ldflags --embed)
 

$(BIN_DIR)/iris+: src/main.c 
	@mkdir -p $(BIN_DIR)
	   $(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@ 


$(BIN_DIR)/resfinder: modules/scripts/resfinder.c libnet/libnet.c
	@mkdir -p $(BIN_DIR)
	   $(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

$(BIN_DIR)/subdomain: modules/scripts/subdomain.c libnet/libnet.c
	@mkdir -p $(BIN_DIR)
	   $(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

install: all 
	@echo "Installing to $(INSTALL_DIR)..."
	@mkdir -p $(INSTALL_DIR)
	install -m 755 $(BIN_DIR)/iris+ $(INSTALL_DIR)/iris+
	install -m 755 $(BIN_DIR)/resfinder $(INSTALL_DIR)/resfinder
	install -m 755 $(BIN_DIR)/subdomain $(INSTALL_DIR)/subdomain

.PHONY: uninstall
uninstall:
	@echo "Removing binaries from $(INSTALL_DIR)..."
	rm -f $(TARGET)
	rm -f $(INSTALL_DIR)/iris+
	rm -f $(INSTALL_DIR)/resfinder
	rm -f $(INSTALL_DIR)/subdomain


