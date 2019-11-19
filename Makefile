CC = gcc
CFLAGS = -Wall -pedantic -ansi 
TARGET = prog

SOURCE = .\source


$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

run: $(TARGET)
	@$(TARGET)
