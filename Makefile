CC=gcc
CFLAGS=-Wall -Wextra -std=c11

SRC=./src/main.c ./src/todo.c ./src/fileio.c ./src/ui.c
EXEC=todo-cli

all: 
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

clean:
	rm -f $(EXEC)

run: all
	./$(EXEC)
