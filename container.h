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

Vertex* initVeertex(double x, double y, double z, double w);
void vertexPush(Vertex** v, double x, double y, double z, double w);
void vertexPop(Vertex** v);
#endif  // CONTAINER_H