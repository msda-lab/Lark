#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
public:
    Matrix();
    Matrix(int _size);
    Matrix(int _row, int _column);
    ~Matrix();

public:
    void    SetMatrixValue(int _row, int _column, double _value);
    double  GetMatrixValue(int _row, int _column) const;

private:
    double  **_matrix;
    void    InitializeMatrix();
    int     matrix_type;
};

#endif  // MATRIX_H