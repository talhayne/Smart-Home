.PHONY: run clean gdb

CC = g++
CPPFLAGS = -ansi -pedantic -Wall -Werror -std=c++03 -g
LDFLAGS = -g -pthread

INC_DIR=../../include
LIB_PATH=../../LIB
CPPFLAGS+=-I$(INC_DIR)
CPPFLAGS+=-fPIC -shared

LIB_SRC=IEventRetriever.cpp IEventPublish.cpp EventStore.cpp

OBJECTS=$(SOURCES:.cpp=.o)
LIB_OBJ=$(LIB_SRC:.cpp=.o)

$(TARGET): $(OBJECTS) libs
	$(CC) $(OBJECTS) -o $(TARGET) -L$(LIB_PATH) -ldl -lSMART -lWaitableQueue

libs: mklibs libSMART.a

mklibs:
	mkdir -p $(LIB_PATH)
	make -C WaitableQueue

libSMART.a: $(LIB_OBJ) 
	ar rcs $(LIB_PATH)/libSMART.a $(LIB_OBJ)
	
include depends

depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) $(LIB_SRC) > depends

clean:
	-rm $(TARGET) *.o depends
	make -C WaitableQueue clean
	
run:  $(TARGET)
	 ./$(TARGET)

gdb:  $(TARGET)
	 gdb -q ./$(TARGET)
	

