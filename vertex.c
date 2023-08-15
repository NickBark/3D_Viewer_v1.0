#include "vertex.h"

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
    v->prev = NULL;

    return v;
}

void vertexPushBack(LinkedListVertex* list, double x, double y, double z,
                    double w, int index) {
    Vertex* newVertex = initVeertex(x, y, z, w);
    newVertex->index = index;
    if (!list->tail) {
        list->head = newVertex;
        list->current = newVertex;
        list->tail = newVertex;
    } else {
        list->tail->next = newVertex;
        list->tail->next->prev = list->tail;
        list->tail = list->tail->next;
    }
    list->vertexCount++;
}

int vertexPop(LinkedListVertex* list) {
    int ret = 0;
    if (list->head == NULL) {
        ret = 1;
    } else {
        Vertex* tmp = list->head;
        list->head = list->head->next;
        list->current = list->head;
        list->vertexCount--;
        free(tmp);
    }

    return ret;
}

void printVertexList(LinkedListVertex* list) {
    Vertex* current = list->head;
    int i = 0;
    while (current != NULL) {
        i++;
        printf("v # %d: %.15lf %.15lf %.15lf %lf\n", current->index, current->x,
               current->y, current->z, current->w);
        current = current->next;
    }
    printf("NULL\n");
    printf("i:%d\n", i);
}

Vertex* findVertex(LinkedListVertex* list, int index) {
    Vertex* ret = NULL;
    int curIn = list->current->index;

    if (index <= list->vertexCount && index >= 1) {
        if (curIn < index) {
            for (int i = curIn; i != index; i++) {
                list->current = list->current->next;
            }
        } else if (curIn > index) {
            for (int i = curIn; i != index; i--) {
                list->current = list->current->prev;
            }
        }
        ret = list->current;
    }

    return ret;
}
