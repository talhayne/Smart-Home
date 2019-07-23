.PHONY: run clean gdb

CC = g++

CPPFLAGS = -ansi -pedantic -Wall -Werror -std=c++03 -g
LDFLAGS = -g

INC_DIR=../include
LIB_PATH=../LIB
CPPFLAGS+=-I$(INC_DIR)
CPPFLAGS+=-fPIC -shared

LIB_SRC=Event.cpp EventKey.cpp

OBJECTS=$(SOURCES:.cpp=.o)
LIB_OBJ=$(LIB_SRC:.cpp=.o)

libs: mklibs libSMART.a

mklibs:
	mkdir -p $(LIB_PATH)

libSMART.a: $(LIB_OBJ) 
	ar rcs $(LIB_PATH)/libSMART.a $(LIB_OBJ) 


