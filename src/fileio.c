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
  }
}

// for reference so I don't need to go looking for it in chatGPT
// void load_todos(const char *filename, Todo todos[], int *count) {
//     FILE *file = fopen(filename, "r");
//     if (!file) {
//         perror("Failed to open file");
//         exit(1);
//     }
//
//     char line[512]; // Buffer for each line
//     *count = 0; // Reset the count
//
//     while (fgets(line, sizeof(line), file)) {
//         // Strip newline character if present
//         line[strcspn(line, "\n")] = '\0';
//
//         // Split the line by '|'
//         char *id_str = strtok(line, "|");
//         char *desc_str = strtok(NULL, "|");
//         char *done_str = strtok(NULL, "|");
//
//         if (id_str && desc_str && done_str) {
//             Todo t;
//             t.id = atoi(id_str); // Convert string to int
//             strncpy(t.description, desc_str, sizeof(t.description) - 1);
//             t.description[sizeof(t.description) - 1] = '\0'; //
//             null-terminate just in case t.done = atoi(done_str);
//
//             todos[*count] = t;
//             (*count)++;
//         }
//     }
//
//     fclose(file);
// }
//
