
#include <time.h>

#include "file_read.h"
#include "s21_viewer_core.h"

int main(int argc, char** argv) {
    double time_spent = 0.0;
    clock_t begin = clock();

    // system("clear");
    printf("3D_Viewer\n");
    LinkedListPolygon poly;
    poly.head = NULL;
    poly.tail = NULL;
    poly.current = NULL;
    poly.polygonCount = 0;

    LinkedListVertex list;
    list.head = NULL;
    list.tail = NULL;
    list.current = NULL;
    list.vertexCount = 0;

    if (argc > 1) {
        if (readFile(argv[1], &list, &poly)) {
            printf("ERROR\n");
        } else {
            // Polygon* current = NULL;
            // for (int i = 0; i < 255; i++) {
            //     current = findPoly(&poly, 35288);

            //     if (current && current->pointArr[i])
            //         printf("%d", current->pointArr[i]);
            //     else
            //         break;
            // }

            // Polygon* curP = NULL;
            // Vertex* curV = NULL;
            // int exit = 0;
            // for (int j = 0; j < 255; j++) {
            //     // if (exit) break;
            //     for (int i = 1; i <= poly.polygonCount; i++) {
            //         curP = findPoly(&poly, i);
            //         if (curP) {
            //             if (!curP->pointArr[j]) {
            //                 exit = 1;
            //                 break;
            //             }
            //             curV = findVertex(&list, curP->pointArr[j]);
            //             // if (curV)
            //             //     printf("%d--> x:%lf y:%lf z:%lf\n",
            //             //            curP->pointArr[j], curV->x, curV->y,
            //             //            curV->z);
            //             // else
            //             //     printf("NULL\n");
            //         } else {
            //             printf("NULL and EXIT\n");
            //             break;
            //         }
            //     }
            // }

            printVertexList(&list);
            // printPolyList(&poly);
            printf("OK\n");
            // printf("vc: %d\n", list.vertexCount);
            // Vertex* ppp = findVertex(&list, 35290);
            // printf("x: %lf\n", ppp ? ppp->x : 0);

            // Vertex* qqq = findVertex(&list, 1);
            // if (qqq) printf("x: %lf y:%lf z:%lf\n", qqq->x, qqq->y, qqq->z);

            // for (int i = 0; i < 1; i++) {
            // scale(&list, 3., 3., 3.);
            // scale(&list, 1. / 3., 1. / 3., 1. / 3.);
            // rotate(&list, 0.523599, 'Y', 'L');
            // rotate(&list, 0.523599, 'Y', 'R');
            // move(&list, 1, 2, 3);
            // move(&list, -1, -2, -3);
            // }
            // findVertex(&list, 1);
            // printVertexList(&list);

            // printf("%d\n", list.vertexCount);
            // Vertex* qqq = findVertex(&list, 35290);
            // if (qqq) printf("x: %lf y:%lf z:%lf\n", qqq->x, qqq->y, qqq->z);
            // qqq = findVertex(&list, -1);
            // if (qqq) printf("x: %lf y:%lf z:%lf\n", qqq->x, qqq->y, qqq->z);
            // qqq = list.current;
            // if (qqq) printf("current index:%d\n", qqq->index);
            // if (qqq) printf("x: %lf y:%lf z:%lf\n", qqq->x, qqq->y, qqq->z);
            // qqq = findVertex(&list, 100);
            // if (qqq) printf("x: %lf y:%lf z:%lf\n", qqq->x, qqq->y, qqq->z);
        }
    }

    while (!vertexPop(&list)) {
    }

    while (!polyPop(&poly)) {
    }

    clock_t end = clock();

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("The elapsed time is %f seconds\n", time_spent);

    return 0;
}
