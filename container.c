#include "container.h"

Vertex* initVeertex(double x, double y, double z, double w) {
    Vertex* v = malloc(sizeof(Vertex));
    if (!v) {
        exit(EXIT_FAILURE);
    }
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
    v->next = NULL;

    return v;
}

void vertexPushBack(LinkedListVertex* list, double x, double y, double z,
                    double w) {
    Vertex* newVertex = initVeertex(x, y, z, w);
    if (!list->tail) {
        list->head = newVertex;
        list->tail = newVertex;
    } else {
        list->tail->next = newVertex;
        list->tail = list->tail->next;
    }
    list->vertexCount++;
}

int vertexPop(Vertex** v) {
    int ret = 0;
    if (*v == NULL) {
        ret = 1;
    } else {
        Vertex* tmp = *v;
        *v = (*v)->next;
        free(tmp);
    }

    return ret;
}

void printVertexList(LinkedListVertex* list) {
    Vertex* current = list->head;
    while (current != NULL) {
        printf("v: %lf %lf %lf %lf\n", current->x, current->y, current->z,
               current->w);
        current = current->next;
    }
    printf("NULL\n");
}

Vertex* findVertex(LinkedListVertex* list, int index) {
    Vertex* current = list->head;

    if (index > list->vertexCount || index < 1) {
        current = NULL;
    } else {
        for (int i = 1; i < index; i++) {
            current = current->next;
        }
    }

    return current;
}