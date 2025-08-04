#include "fileio.h"
#include <stdio.h>
#include <stdlib.h>

void read_todos() {
  FILE *todo_file = fopen("todos.txt", "r");
  if (todo_file == NULL) {
    perror("Error opening file!");
    exit(1);
  }

  char line[512];
  while (fgets(line, sizeof(line), todo_file)) {
    printf("Read line: %s", line);
  }

  fclose(todo_file);
}
