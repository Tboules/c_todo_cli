#ifndef TODO_H
#define TODO_H

#define MAX_TODOS 100

typedef struct {
  int id;
  char description[256];
  int done;
} Todo;

void add_todos(Todo todos[], int *count, const char *description);
void mark_done(Todo todos[], int count, int id);
void list_todos(Todo todos[], int count);

#endif
