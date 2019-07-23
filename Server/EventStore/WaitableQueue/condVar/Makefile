TARGET = test.out
.PHONY: run clean gdb

CC = g++
CPPFLAGS = -ansi -pedantic -Wall -Werror -std=c++03 -g
LDFLAGS = -g -pthread

INC_DIR=../include
LIB_PATH=../../../../LIB
CPPFLAGS+=-I$(INC_DIR) 

SOURCES=test.cpp
LIB_SRC=condVar.cpp

OBJECTS=$(SOURCES:.cpp=.o)
LIB_OBJ=$(LIB_SRC:.cpp=.o)

$(TARGET): $(OBJECTS) libs
	$(CC) $(OBJECTS) -o $(TARGET) -L$(LIB_PATH) $(LDFLAGS) -lWaitableQueue

libs: mklibs libWaitableQueue.a

mklibs:
	mkdir -p $(LIB_PATH)

libWaitableQueue.a: $(LIB_OBJ) 
	ar rcs $(LIB_PATH)/libWaitableQueue.a $(LIB_OBJ) 

include depends

depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) $(LIB_SRC) > depends

clean:
	-rm $(TARGET) *.o depends
	
run:  $(TARGET)
	 ./$(TARGET)

gdb:  $(TARGET)
	 gdb -q ./$(TARGET)
	


