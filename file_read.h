#ifndef FILE_READ_H
#define FILE_READ_H

#include "vertex.h"
#include "dependencies.h"

int readFile(const char* name, LinkedListVertex* list);
int parsStr(char* input, LinkedListVertex* list);

#endif  // FILE_READ_H