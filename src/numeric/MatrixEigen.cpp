#include "MatrixEigen.h"

MatrixEigen::MatrixEigen(int _row, int _column)
{
    matrix = MatrixXd(_row, _column);
}

MatrixEigen::~MatrixEigen() {}

void MatrixEigen::GetInverseMatrix()
{
    matrix_inverse = matrix.inverse();
}

void MatrixEigen::SetValue(int _row, int _column, double _value)
{
    matrix(_row, _column) = _value;
}

void MatrixEigen::AddValue(int _row, int _column, double _value)
{
    matrix(_row, _column) += _value;
}

double MatrixEigen::GetValue(int _row, int _column)
{
    double _value = matrix(_row, _column);
    return _value;
}