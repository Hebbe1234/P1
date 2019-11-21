CC = gcc
CFLAGS = -Wall -pedantic -ansi 
TARGET = prog
TEST_TARGET = test
BASEDIR = ../..

SOURCE =  $(wildcard source/*.c)
TESTS =  $(wildcard tests/*.c)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c $(SOURCE) -o $(TARGET)

$(TEST_TARGET): 
	$(CC) $(CFLAGS) $(TESTS) $(SOURCE) -o $(TEST_TARGET)

run: $(TARGET)
	@$(TARGET)

tests: $(TEST_TARGET)
	@$(TEST_TARGET)