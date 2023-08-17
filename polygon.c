#include "polygon.h"

Polygon* initPoly(int* pointArr, int num) {
    Polygon* newNode = malloc(sizeof(Polygon));
    if (!newNode) {
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < POINT_ARR_NUM; i++) {
        newNode->pointArr[i] = pointArr[i];
    }
    newNode->numOfElem = num;

    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void polyPushBack(LinkedListPolygon* list, int* pointArr, int num) {
    Polygon* newNode = initPoly(pointArr, num);

    if (!list->tail) {
        list->head = newNode;
        list->current = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail->next->prev = list->tail;
        list->tail = list->tail->next;
    }

    list->polygonCount++;
    list->tail->index = list->polygonCount;
}

int polyPop(LinkedListPolygon* list) {
    int ret = 0;
    if (list->head == NULL) {
        ret = 1;
    } else {
        Polygon* tmp = list->head;
        list->head = list->head->next;
        list->current = list->head;
        list->polygonCount--;
        free(tmp);
    }

    return ret;
}

void printPolyList(LinkedListPolygon* list) {
    Polygon* current = list->head;
    int i = 0;
    while (current != NULL) {
        i++;
        printf("f: ");
        for (int i = 0; current->pointArr[i] != 0; i++) {
            printf("%d ", current->pointArr[i]);
        }
        printf("   numOfElem: %d", current->numOfElem);
        printf("\n");
        current = current->next;
    }
    printf("NULL\n");
    printf("i:%d\n", i);
}

Polygon* findPoly(LinkedListPolygon* list, int index) {
    Polygon* ret = NULL;
    int curIn = list->current->index;

    if (index <= list->polygonCount && index >= 1) {
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