#ifndef POLYGON_H
#define POLYGON_H

#include "dependencies.h"

typedef struct Polygon {
    int pointArr[255];
    struct Polygon* next;
    struct Polygon* prev;
    int index;
} Polygon;

typedef struct LinkedListPolygon {
    Polygon* head;
    Polygon* tail;
    Polygon* current;
    int polygonCount;
} LinkedListPolygon;

Polygon* initPoly(int* pointArr);
void polyPushBack(LinkedListPolygon* list, int* pointArr);
int polyPop(LinkedListPolygon* list);
void printPolyList(LinkedListPolygon* list);
Polygon* findPoly(LinkedListPolygon* list, int index);
// void printVertexList(LinkedListVertex* list);
// Vertex* findVertex(LinkedListVertex* list, int index);

#endif  // POLYGON_H