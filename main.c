#include "file_read.h"

int main(int argc, char** argv) {
    system("clear");
    printf("3D_Viewer\n");
    LinkedListVertex list;
    list.head = NULL;
    list.tail = NULL;
    list.vertexCount = 0;

    if (argc > 1) {
        if (readFile(argv[1], &list)) {
            printf("ERROR\n");
        } else {
            printVertexList(&list);
            printf("OK\n");
            printf("vc: %d\n", list.vertexCount);
            Vertex* ppp = findVertex(&list, 35290);
            printf("x: %lf\n", ppp ? ppp->x : 0);

            // int n = list.vertexCount;
            // for (int i = 0; i < n; i++) vertexPop(&list);
            Vertex* qqq = findVertex(&list, 1);
            if (qqq) printf("x: %lf y:%lf z:%lf\n", qqq->x, qqq->y, qqq->z);
        }
    }

    return 0;
}
