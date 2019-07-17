#include "Matrix.h"

#include <iostream>

Matrix::Matrix()
{
    std::cout << "Value Needed" << std::endl;
}

Matrix::~Matrix()
{}

Matrix::Matrix(int _size)
{
    std::cout << "Initialize Matrix " << _size;
    std::cout << " x " << _size << std::endl;

    _matrix = new double *[_size];
    for(int i = 0; i < _size; ++i)
    {
        _matrix[i] = new double[_size];
    }
    for(int i = 0; i < _size; ++i)
    {
        for(int j = 0; j < _size; ++j)
        {
            _matrix[i][j] = 0.0;
        }
    }
}

Matrix::Matrix(int _row, int _column)
{
    std::cout << "Initialize Matrix " << _row;
    std::cout << " x " << _column << std::endl;

    _matrix = new double *[_row];
    for(int i = 0; i < _row; ++i)
    {
        _matrix[i] = new double[_row];
    }
    for(int i = 0; i < _row; ++i)
    {
        for(int j = 0; j < _column; ++j)
        {
            _matrix[i][j] = 0.0;
        }
    }
}

void Matrix::SetMatrixValue(int _row, int _column, double _value)
{
    _matrix[_row][_column] = _value;
}

double Matrix::GetMatrixValue(int _row, int _column) const
{
    return _matrix[_row][_column];
}