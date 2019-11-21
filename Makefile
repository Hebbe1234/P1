CC = gcc
CFLAGS = -Wall -pedantic -ansi 
TARGET = prog
TEST_TARGET = test
BASEDIR = ../..

SOURCE =  $(BASEDIR)/source
TESTS =  $(wildcard tests/*.c)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

$(TEST_TARGET): 
	$(CC) $(CFLAGS) $(TESTS) -o $(TEST_TARGET)

run: $(TARGET)
	@$(TARGET)

tests: $(TEST_TARGET)
	@$(TEST_TARGET)