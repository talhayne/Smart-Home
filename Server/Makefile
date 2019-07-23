.PHONY: run clean gdb

CC = g++

CPPFLAGS = -ansi -pedantic -Wall -Werror -std=c++03 -g

LDFLAGS = -g

INC_DIR=../include
LIB_PATH=../LIB
CPPFLAGS+=-I$(INC_DIR)
CPPFLAGS+=-fPIC -shared

LIB_SRC=Server.cpp

OBJECTS=$(SOURCES:.cpp=.o)
LIB_OBJ=$(LIB_SRC:.cpp=.o)

$(TARGET): $(OBJECTS) libs
	$(CC) $(OBJECTS) -o $(TARGET) -L$(LIB_PATH) -lSMART -lWaitableQueue

libs: mklibs libSMART.a

mklibs:
	make -C SubManager
	make -C Dispatcher
	make -C EventStore
	mkdir -p $(LIB_PATH)
	

libSMART.a: $(LIB_OBJ) 
	ar rcs $(LIB_PATH)/libSMART.a $(LIB_OBJ) 

include depends

depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) $(LIB_SRC) > depends

clean:
	make -C SubManager clean
	make -C Dispatcher clean
	make -C EventStore clean
	-rm $(TARGET) *.o depends
	
run:  $(TARGET)
	 ./$(TARGET)

gdb:  $(TARGET)
	 gdb -q ./$(TARGET)
	

