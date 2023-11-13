.PHONY: objs shared static

LIB_STATIC_NAME := libstatic.a
LIB_SHARD_NAME := libshared.so

CUR_DIR := .
BIN_DIR:= $(CUR_DIR)/bin
OBJS_DIR := $(CUR_DIR)/objs
SRC_DIR := $(CUR_DIR)/src

LIB_DIR := $(CUR_DIR)/lib
LIB_STATIC := $(LIB_DIR)/static
LIB_SHARE := $(LIB_DIR)/shared

CC := gcc

mk_objs:
	$(CC) -c main.c  -o $(OBJS_DIR)/main.o
	$(CC) -c -fPIC $(SRC_DIR)/foo.c  -o $(OBJS_DIR)/foo.o
	$(CC) -c -fPIC $(SRC_DIR)/bar.c  -o $(OBJS_DIR)/bar.o

mk_shared:
	$(CC) -shared $(OBJS_DIR)/foo.o $(OBJS_DIR)/bar.o -o $(LIB_SHARE)/$(LIB_SHARD_NAME)

mk_static:
	ar -rcs $(LIB_STATIC)/$(LIB_STATIC_NAME) $(OBJS_DIR)/foo.o $(OBJS_DIR)/bar.o

install: all
	install $(LIB_SHARE)/$(LIB_SHARD_NAME) /usr/lib

all: mk_objs mk_static mk_shared
	$(CC) $(OBJS_DIR)/main.o -L$(LIB_STATIC) -lstatic -o $(BIN_DIR)/statically-linked
	$(CC) $(OBJS_DIR)/main.o -L$(LIB_SHARE) -lshared -o $(BIN_DIR)/use-shared-library

clean: 
	rm -rf $(OBJS_DIR)/*
	rm -rf $(BIN_DIR)/*
	rm -rf $(LIB_STATIC)/*
	rm -rf $(LIB_SHARE)/*
	
