CC = gcc
CFLAGS = -Wall -pedantic -ansi 
TARGET = prog

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

run: $(TARGET)
	@$(TARGET)
