#ifndef CONTAINER_H
#define CONTAINER_H

#include "dependencies.h"

typedef struct Vertex {
    double x;
    double y;
    double z;
    double w;
    struct Vertex* next;
} Vertex;

typedef struct LinkedListVertex {
    Vertex* head;
    Vertex* tail;
    int vertexCount;
} LinkedListVertex;

Vertex* initVeertex(double x, double y, double z, double w);
void vertexPushBack(LinkedListVertex* list, double x, double y, double z,
                    double w);
int vertexPop(Vertex** v);
void printVertexList(LinkedListVertex* list);
Vertex* findVertex(LinkedListVertex* list, int index);

#endif  // CONTAINER_H