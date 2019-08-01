#ifndef MATRIXEIGEN_H
#define MATRIXEIGEN_H

#include "../include/eigen/Core"
#include "../include/eigen/Dense"

#include <iostream>

using namespace Eigen;
using namespace std;

class MatrixEigen
{
public:
    MatrixEigen(int _row, int _column);
    ~MatrixEigen();

public:
    void GetInverseMatrix();

public:
    void SetValue(int _row, int _column, double _value);
    void AddValue(int _row, int _column, double _value);
    double GetValue(int _row, int _column);

private:
    MatrixXd matrix;
    MatrixXd matrix_inverse;
};

#endif // MATRIXEIGEN_H