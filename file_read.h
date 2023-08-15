#ifndef FILE_READ_H
#define FILE_READ_H

#include "dependencies.h"
#include "polygon.h"
#include "vertex.h"

int readFile(const char* name, LinkedListVertex* list, LinkedListPolygon* poly);
int parsStr(char* input, LinkedListVertex* list, int* index,
            LinkedListPolygon* poly);
int parsToken(char* input);

#endif  // FILE_READ_H
