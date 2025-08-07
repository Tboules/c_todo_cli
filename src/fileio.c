#include "fileio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// loading todo items
void load_todos(Todo todos[], int *count) {
  FILE *todo_file = fopen("todos.txt", "r");
  if (todo_file == NULL) {
    perror("Error opening file!");
    exit(1);
  }

  char line[512];
  *count = 0;
  while (fgets(line, sizeof(line), todo_file)) {
    // strip newline characters if present
    line[strcspn(line, "\n")] = '\0';

    // grab the values from the document
    char *id_str = strtok(line, "|");
    char *desc_str = strtok(NULL, "|");
    char *done_str = strtok(NULL, "|");

    if (id_str && desc_str && done_str) {
      Todo t;
      t.id = atoi(id_str);
      strncpy(t.description, desc_str, sizeof(t.description) - 1);
      t.description[sizeof(t.description) - 1] = '\0';
      t.done = atoi(done_str);

      todos[*count] = t;
      (*count)++;
    }
  }

  fclose(todo_file);
}
