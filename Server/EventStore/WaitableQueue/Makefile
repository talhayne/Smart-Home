.PHONY: run clean gdb

CC = g++
CPPFLAGS = -ansi -pedantic -Wall -Werror -std=c++03 -g
LDFLAGS = -g -pthread

INC_DIR=include
LIB_PATH=../../../LIB
CPPFLAGS+=-I$(INC_DIR) 

SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)

libs: mklibs libWaitableQueue.a

mklibs:
	mkdir -p $(LIB_PATH)
	make -C thread
	make -C mutex
	make -C condVar

libWaitableQueue.a: $(OBJECTS) 
	ar rcs $(LIB_PATH)/libWaitableQueue.a $(OBJECTS) 

clean:
	-rm $(TARGET) *.o depends
	make -C mutex clean
	make -C condVar clean
	make -C thread clean
	
run:  $(TARGET)
	 ./$(TARGET)

gdb:  $(TARGET)
	 gdb -q ./$(TARGET)
	
