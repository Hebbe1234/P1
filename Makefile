CC = gcc
STD = c89
CFLAGS = -Wall -pedantic -ansi -std=$(STD)
TARGET = prog
TEST_TARGET = unit_test
BASEDIR = ../..

EXT = .exe

SOURCE =  $(wildcard source/*.c)
TESTS =  $(wildcard tests/*.c)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c $(SOURCE) -o $(TARGET)$(EXT)

$(TEST_TARGET): 
	$(CC) $(CFLAGS) $(TESTS) $(SOURCE) -o $(TEST_TARGET)$(EXT)

run: $(TARGET)
	@$(TARGET)

test: $(TEST_TARGET)
	@$(TEST_TARGET)$(EXT)

tests: $(TEST_TARGET)
