#include <stdio.h>
#include <stdlib.h>

#include "file_read.h"

int main(int argc, char** argv) {
    system("clear");
    printf("3D_Viewer\n");

    if (argc > 1) {
        if (readFile(argv[1])) {
            printf("ERROR\n");
        } else {
            printf("OK\n");
        }
    }

    return 0;
}