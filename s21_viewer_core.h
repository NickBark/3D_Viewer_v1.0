#ifndef S21_VIEWER_CORE_H
#define S21_VIEWER_CORE_H

#include "dependencies.h"
#include "s21_matrix.h"
#include "vertex.h"

void s21_move(LinkedListVertex* list, double x_move, double y_move,
              double z_move);

// axis : 'X' / 'Y' / 'Z'
// route: 'R' / 'L'
void s21_rotate(LinkedListVertex* list, double angle, char axis, char route);
void s21_scale(LinkedListVertex* list, double x_sc, double y_sc, double z_sc);

#endif  // S21_VIEWER_CORE_H
