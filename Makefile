TARGET= Src/main
SOURCES=$(wildcard Src/*.cpp Src/*/*.cpp Src/*/*/*.cpp Src/*/*/*/*.cpp Src/*/*/*/*/*.cpp)
OBJS=$(SOURCES:.cpp=.o)
INC_FLAGS=-I../include
CC=g++
CFLAGS= -pedantic -Wall -Wconversion -ansi -Wno-deprecated -g $(INC_FLAGS)
CXXFLAGS=$(CFLAGS)
LDFLAGS=-g
.PHONY: clean run gdb
$(TARGET): $(OBJS)
include .depends
.depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > .depends
clean:
	rm -f $(OBJS) $(TARGET) .depends
run: $(TARGET)
	./$(TARGET)
gdb: $(TARGET)
	gdb -q ./$(TARGET)
test:
	valgrind --leak-check=full ./$(TARGET)

