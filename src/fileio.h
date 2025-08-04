#ifndef FILEIO_H
#define FILEIO_H

#include "todo.h"

void read_todos();

void load_todos(Todo todos[], int *count);
void save_todos(const Todo todos[], int count);

#endif
