#ifndef TRANSFORMMATRIX_H
#define TRANSFORMMATRIX_H
#include "point.h"
#include <iostream>

#define MATRIX_COL 4
#define MATRIX_ROW 4

class TransformMatrix
{
private:
    float _matr[MATRIX_COL][MATRIX_ROW];
public:
    TransformMatrix();
    TransformMatrix(float matr[MATRIX_COL][MATRIX_ROW]);
    TransformMatrix operator*(TransformMatrix _transformMatrix);
    Point TransformPoint(Point point);
};

#endif // TRANSFORMMATRIX_H
