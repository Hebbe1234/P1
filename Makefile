CC = gcc
CFLAGS = -Wall -pedantic -ansi 
TARGET = prog
TEST_TARGET = test
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

tests: $(TEST_TARGET)
	@$(TEST_TARGET)