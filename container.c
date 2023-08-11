#include "container.h"

Vertex* initVeertex(double x, double y, double z, double w) {
    Vertex* v = malloc(sizeof(Vertex));
    if (!v) {
        exit(1);
    }
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
    v->next = NULL;

    return v;
}

void vertexPush(Vertex** v, double x, double y, double z, double w) {
    Vertex* newVertex = initVeertex(x, y, z, w);
    if (!(*v)) {
        v = newVertex;
    } else {
        (*v)->next = newVertex;
    }
}

void vertexPop(Vertex** v) {}