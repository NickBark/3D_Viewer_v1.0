#include "s21_viewer_core.h"

void move(LinkedListVertex* list, double x_move, double y_move, double z_move) {
    matrix_t moveMatrix;
    matrix_t startingPoint;
    matrix_t result;

    s21_create_matrix(4, 4, &moveMatrix);
    s21_create_matrix(4, 1, &startingPoint);

    for (int i = 0; i < moveMatrix.columns; i++) {
        moveMatrix.matrix[i][i] = 1;
    }
    moveMatrix.matrix[0][3] = x_move;
    moveMatrix.matrix[1][3] = y_move;
    moveMatrix.matrix[2][3] = z_move;
    int n = list->vertexCount;

    for (int i = 1; i <= n; i++) {
        startingPoint.matrix[0][0] = findVertex(list, 1)->x;
        startingPoint.matrix[1][0] = findVertex(list, 1)->y;
        startingPoint.matrix[2][0] = findVertex(list, 1)->z;
        startingPoint.matrix[3][0] = 1.0;
        s21_mult_matrix(&moveMatrix, &startingPoint, &result);
        vertexPushBack(list, result.matrix[0][0], result.matrix[1][0],
                       result.matrix[2][0], 1.0);
        vertexPop(list);
    }
}

void rotate(LinkedListVertex* list, double angle, char axis, char route) {
    matrix_t rotateMatrix;
    matrix_t startingPoint;
    matrix_t result;

    s21_create_matrix(3, 3, &rotateMatrix);
    s21_create_matrix(3, 1, &startingPoint);

    rotateMatrix.matrix[0][0] = cos(angle);
    rotateMatrix.matrix[1][1] = cos(angle);
    rotateMatrix.matrix[2][2] = 1.0;

    if (route == 'R') {
        rotateMatrix.matrix[0][1] = sin(angle);
        rotateMatrix.matrix[1][0] = -sin(angle);
    } else if (route == 'L') {
        rotateMatrix.matrix[0][1] = -sin(angle);
        rotateMatrix.matrix[1][0] = sin(angle);
    }

    startingPoint.matrix[2][0] = 1.0;
    if (axis == 'X') {
        for (int i = 0; i < list->vertexCount; i++) {
            startingPoint.matrix[0][0] = list->head->y;
            startingPoint.matrix[1][0] = list->head->z;
            s21_mult_matrix(&rotateMatrix, &startingPoint, &result);
            vertexPushBack(list, list->head->x, result.matrix[0][0],
                           result.matrix[1][0], 1.0);
            vertexPop(list);
        }
    } else if (axis == 'Y') {
        for (int i = 0; i < list->vertexCount; i++) {
            startingPoint.matrix[0][0] = list->head->x;
            startingPoint.matrix[1][0] = list->head->z;
            s21_mult_matrix(&rotateMatrix, &startingPoint, &result);
            vertexPushBack(list, result.matrix[0][0], list->head->y,
                           result.matrix[1][0], 1.0);
            vertexPop(list);
        }
    } else if (axis == 'Z') {
        for (int i = 0; i < list->vertexCount; i++) {
            startingPoint.matrix[0][0] = list->head->x;
            startingPoint.matrix[1][0] = list->head->y;
            s21_mult_matrix(&rotateMatrix, &startingPoint, &result);
            vertexPushBack(list, result.matrix[0][0], result.matrix[1][0],
                           list->head->z, 1.0);
            vertexPop(list);
        }
    }
}