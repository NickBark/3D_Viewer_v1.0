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
    Vertex* current = NULL;
    for (int i = 1; i <= n; i++) {
        current = findVertex(list, i);
        startingPoint.matrix[0][0] = current->x;
        startingPoint.matrix[1][0] = current->y;
        startingPoint.matrix[2][0] = current->z;
        startingPoint.matrix[3][0] = 1.0;
        s21_mult_matrix(&moveMatrix, &startingPoint, &result);
        current->x = result.matrix[0][0];
        current->y = result.matrix[1][0];
        current->z = result.matrix[2][0];
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
    int n = list->vertexCount;
    Vertex* current = NULL;
    if (axis == 'X') {
        for (int i = 1; i <= n; i++) {
            current = findVertex(list, i);
            startingPoint.matrix[0][0] = current->y;
            startingPoint.matrix[1][0] = current->z;
            s21_mult_matrix(&rotateMatrix, &startingPoint, &result);
            current->y = result.matrix[0][0];
            current->z = result.matrix[1][0];
        }
    } else if (axis == 'Y') {
        for (int i = 1; i <= n; i++) {
            current = findVertex(list, i);
            startingPoint.matrix[0][0] = current->x;
            startingPoint.matrix[1][0] = current->z;
            s21_mult_matrix(&rotateMatrix, &startingPoint, &result);
            current->x = result.matrix[0][0];
            current->z = result.matrix[1][0];
        }
    } else if (axis == 'Z') {
        for (int i = 1; i <= n; i++) {
            current = findVertex(list, i);
            startingPoint.matrix[0][0] = current->x;
            startingPoint.matrix[1][0] = current->y;
            s21_mult_matrix(&rotateMatrix, &startingPoint, &result);
            current->x = result.matrix[0][0];
            current->y = result.matrix[1][0];
        }
    }
}

void scale(LinkedListVertex* list, double x_sc, double y_sc, double z_sc) {
    matrix_t scaleMatrix;
    matrix_t startingPoint;
    matrix_t result;
    double tmpScale[4] = {x_sc, y_sc, z_sc, 1.0};

    s21_create_matrix(4, 4, &scaleMatrix);
    s21_create_matrix(4, 1, &startingPoint);

    for (int i = 0; i < scaleMatrix.columns; i++) {
        scaleMatrix.matrix[i][i] = tmpScale[i];
    }

    int n = list->vertexCount;
    Vertex* current = NULL;
    for (int i = 1; i <= n; i++) {
        current = findVertex(list, i);
        startingPoint.matrix[0][0] = current->x;
        startingPoint.matrix[1][0] = current->y;
        startingPoint.matrix[2][0] = current->z;
        startingPoint.matrix[3][0] = 1.0;
        s21_mult_matrix(&scaleMatrix, &startingPoint, &result);
        current->x = result.matrix[0][0];
        current->y = result.matrix[1][0];
        current->z = result.matrix[2][0];
    }
}
