TARGET = test.out
.PHONY: run clean gdb

CC = g++

CPPFLAGS = -ansi -pedantic -Wall -Werror -std=c++03 -g
LDFLAGS = -g -pthread

INC_DIR=../../../include
LIB_PATH=../../../LIB
CPPFLAGS += -I$(INC_DIR)
CPPFLAGS += -fPIC

SOURCES=test.cpp
LIB_SRC=fireAlarm.cpp

OBJECTS=$(SOURCES:.cpp=.o)
LIB_OBJ=$(LIB_SRC:.cpp=.o)

$(TARGET): $(OBJECTS) libs
	$(CC) $(OBJECTS) -o $(TARGET) -L$(LIB_PATH) -ldl -lSMART

libs: mklibs libfireAlarm.so

mklibs:
	mkdir -p $(LIB_PATH)

libfireAlarm.so: $(LIB_OBJ)
	$(CC) -shared $(LIB_OBJ) -fPIC -o $(LIB_PATH)/libfireAlarm.so -L$(LIB_PATH) -lSMART 

include depends

depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) $(LIB_SRC) > depends

clean:
	-rm $(TARGET) *.o depends
	
run:
	 ./$(TARGET)

gdb:
	 gdb -q ./$(TARGET)

