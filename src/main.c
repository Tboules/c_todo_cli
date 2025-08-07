#include "fileio.h"
#include "todo.h"
#include <stdio.h>

int main() {
  Todo todos[MAX_TODOS];
  int count = 0;

  load_todos(todos, &count);

  for (int i = 0; i < count; i++) {
    Todo t = todos[i];
    printf("ID: %d\n", t.id);
    printf("Description: %s\n", t.description);
    printf("Done: %s\n", t.done ? "Done" : "Not Done");
    printf("---------------------------------\n");
  }

  return 0;
}
