#ifndef POLYGON_H
#define POLYGON_H

#include "dependencies.h"
#define POINT_ARR_NUM 255

typedef struct Polygon {
    int pointArr[POINT_ARR_NUM];
    int numOfElem;
    struct Polygon* next;
    struct Polygon* prev;
    int index;
} Polygon;

typedef struct LinkedListPolygon {
    Polygon* head;
    Polygon* tail;
    Polygon* current;
    int polygonCount;
    unsigned int numOfIndex;
} LinkedListPolygon;

Polygon* initPoly(int* pointArr, int num);
void polyPushBack(LinkedListPolygon* list, int* pointArr, int num);
int polyPop(LinkedListPolygon* list);
void printPolyList(LinkedListPolygon* list);
Polygon* findPoly(LinkedListPolygon* list, int index);

#endif  // POLYGON_H