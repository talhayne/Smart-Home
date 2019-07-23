TARGET = test
.PHONY: run clean gdb

CC = g++
CPPFLAGS = -ansi -pedantic -Wall -Werror -std=c++03 -g
LDFLAGS = -g -pthread

INC_DIR=./include
LIB_PATH=./LIB
CPPFLAGS+=-I$(INC_DIR)
CFPPLAGS+=-fPIC

SOURCES=test.cpp
LIB_SRC=SmartHome.cpp

OBJECTS=$(SOURCES:.cpp=.o)
LIB_OBJ=$(LIB_SRC:.cpp=.o)

$(TARGET): $(OBJECTS) libs
	$(CC) $(OBJECTS) -o $(TARGET) -L$(LIB_PATH) $(LDFLAGS) -lSMART -ldl -lWaitableQueue
	
libs: mklibs libSMART.a

mklibs:
	mkdir -p $(LIB_PATH)
	make -C Event
	make -C Server
	make -C SetUp

libSMART.a: $(LIB_OBJ) 
	ar rcs $(LIB_PATH)/libSMART.a $(LIB_OBJ) 

include depends

depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) $(LIB_SRC) > depends

clean:
	-rm $(TARGET) *.o depends
	make -C Event clean
	make -C Server clean
	make -C SetUp clean
		
run:  
	 ./$(TARGET)

gdb:
	 gdb -q ./$(TARGET)
