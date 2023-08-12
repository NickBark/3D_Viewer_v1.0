#include "container.h"
#include "dependencies.h"
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
            // printVertexList(&list);
            printf("OK\n");
            printf("vc: %d\n", list.vertexCount);
            Vertex* ppp = findVertex(&list, 35291);
            printf("x: %lf\n", ppp ? ppp->x : 0);
        }
    }

    return 0;
}