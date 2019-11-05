CC = gcc
CFLAGS = -Wall -pedantic -ansi 
TARGET = prog

SOURCE = .\source


$(TARGET): $(SOURCE)\main.c
	$(CC) $(CFLAGS) $(SOURCE)\main.c -o $(TARGET)

run: $(TARGET)
	@$(TARGET)
