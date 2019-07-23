TARGET = test
.PHONY: run clean gdb

CPPFLAGS = -ansi -pedantic -Wall -Werror -std=c++03 -g
LDFLAGS = -g -pthread

INC_DIR=../include
LIB_PATH=../LIB
CPPFLAGS+=-I$(INC_DIR)
CFPPLAGS+=-fPIC

SOURCES=test.cpp
LIB_SRC=DeviceRunable.cpp AgentsContainer.cpp SetUp.cpp

OBJECTS=$(SOURCES:.cpp=.o)
LIB_OBJ=$(LIB_SRC:.cpp=.o)

$(TARGET): $(OBJECTS) libs
	g++ $(OBJECTS) -o $(TARGET) -L$(LIB_PATH) $(LDFLAGS) -lSMART -ldl -lWaitableQueue
	
libs: mklibs libSMART.a

mklibs:
	mkdir -p $(LIB_PATH)
	make -C thread
	make -C Agent
	make -C Parser

libSMART.a: $(LIB_OBJ) 
	ar rcs $(LIB_PATH)/libSMART.a $(LIB_OBJ) 

include depends

depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) $(LIB_SRC) > depends

clean:
	-rm $(TARGET) *.o depends
	make -C Agent clean
	make -C Parser clean
	make -C thread clean
	
run:
	 ./$(TARGET)

gdb:
	 gdb -q ./$(TARGET)
