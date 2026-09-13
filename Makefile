CC = gcc
CFLAGS = -O2 -Wall -Wextra -std=c11

TARGET = guessthenumber
SOURCE = ./src/main.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

install: $(TARGET)
	install -Dm755 $(TARGET) /usr/local/bin/$(TARGET)

uninstall:
	rm -f /usr/local/bin/$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run install uninstall clean
