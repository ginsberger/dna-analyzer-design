TARGET= Src/main
SOURCES=$(wildcard Src/main.cpp Src/DNA/*.cpp Src/Exeptions/*.cpp Src/Reader/*.cpp Src/Writer/*.cpp Src/Test/*.cpp)
OBJS=$(SOURCES:.cpp=.o)
INC_FLAGS=-I../include
CC=g++
CFLAGS= -pedantic -Wall -Werror -Wconversion -ansi -g $(INC_FLAGS)
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

