#ifndef FILE_READ_H
#define FILE_READ_H

#include "dependencies.h"
#include "vertex.h"

int readFile(const char* name, LinkedListVertex* list);
int parsStr(char* input, LinkedListVertex* list, int* index);

#endif  // FILE_READ_H