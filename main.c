#include <time.h>

#include "file_read.h"
#include "s21_viewer_core.h"

int main(int argc, char** argv) {
    double time_spent = 0.0;
    clock_t begin = clock();

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
            // printVertexList(&list);
            printf("OK\n");
            printf("vc: %d\n", list.vertexCount);
            Vertex* ppp = findVertex(&list, 35290);
            // printf("x: %lf\n", ppp ? ppp->x : 0);

            // Vertex* qqq = findVertex(&list, 1);
            // if (qqq) printf("x: %lf y:%lf z:%lf\n", qqq->x, qqq->y, qqq->z);
            // move(&list, 0, 0, 5);
            for (int i = 0; i < 1; i++) {
                scale(&list, 3, 3, 3);
                // rotate(&list, 0.523599, 'Y', 'R');
                // rotate(&list, 0.523599, 'Y', 'L');
            }
            // printVertexList(&list);
            printf("%d\n", list.vertexCount);
            Vertex* qqq = findVertex(&list, 1);
            if (qqq) printf("x: %lf y:%lf z:%lf\n", qqq->x, qqq->y, qqq->z);
        }
    }

    clock_t end = clock();

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("The elapsed time is %f seconds\n", time_spent);

    return 0;
}
