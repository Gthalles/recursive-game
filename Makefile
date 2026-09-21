CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic
TARGET = quiz
SOURCES = src/main.c src/game.c src/questions.c

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)
