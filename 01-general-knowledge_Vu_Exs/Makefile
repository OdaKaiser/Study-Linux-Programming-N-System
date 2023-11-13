.PHONY: objs shared 

CUR_DIR := .
BIN_DIR:= $(CUR_DIR)/bin
OBJS_DIR := $(CUR_DIR)/objs
SRC_DIR := $(CUR_DIR)/src

LIB_DIR := $(CUR_DIR)lib
LIB_STATIC := $(LIB_DIR)/static
LIB_SHARE := $(LIB_DIR)/shared

CC := gcc

mk_objs:
	$(CC) -c -fPIC main.c  -o $(OBJS_DIR)/main.o
	$(CC) -c -fPIC $(SRC_DIR)/foo.c  -o $(OBJS_DIR)/foo.o
	$(CC) -c -fPIC $(SRC_DIR)/bar.c  -o $(OBJS_DIR)/bar.o

mk_shared:


install:


all:


clean: 
	rm -rf $(OBJS_DIR)
	
