#ifndef VERTEX_H
#define VERTEX_H

#include "dependencies.h"

typedef struct Vertex {
    double x;
    double y;
    double z;
    double w;
    struct Vertex* next;
    struct Vertex* prev;
    int index;
} Vertex;

typedef struct LinkedListVertex {
    Vertex* head;
    Vertex* tail;
    Vertex* current;
    int vertexCount;
} LinkedListVertex;

Vertex* initVeertex(double x, double y, double z, double w);
void vertexPushBack(LinkedListVertex* list, double x, double y, double z,
                    double w, int index);
int vertexPop(LinkedListVertex* list);
void printVertexList(LinkedListVertex* list);
Vertex* findVertex(LinkedListVertex* list, int index);

#endif  // VERTEX_H