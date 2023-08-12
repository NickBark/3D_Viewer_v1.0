#ifndef S21_VIEWER_CORE_H
#define S21_VIEWER_CORE_H

#include "dependencies.h"
#include "s21_matrix.h"
#include "vertex.h"

void move(LinkedListVertex* list, double x_move, double y_move, double z_move);
void rotate(LinkedListVertex* list, double angle, char axis, char route);

#endif  // S21_VIEWER_CORE_H
