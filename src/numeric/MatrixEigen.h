#ifndef MATRIXEIGEN_H
#define MATRIXEIGEN_H

#include "../include/eigen/Core"
#include "../include/eigen/Dense"

#include <iostream>

using namespace Eigen;

class MatrixEigen
{
public:
    MatrixEigen(int _matrix_row, int _matrix_column, int _vector_row);
    ~MatrixEigen();

public:                                 // Functions for Print
    void EigenPrintMatrix();            // Ax = b : A
    void EigenPrintMatrixInverse();     // Ax = b : A(-1)
    void EigenPrintVector();            // Ax = b : b
    void EigenPrintVectorSolution();    // Ax = b : x

public:
    void EigenAddMatrixRow(int _matrix_row_count);
    void EigenAddMatrixColumn(int _matrix_column_count);
    void EigenAddVectorRow(int _vector_row_count);

public:
    void EigenSetMatrixValue(int _matrix_row, int _matrix_column, double _matrix_value);
    void EigenAddMatrixValue(int _matrix_row, int _matrix_column, double _matrix_value);
    double EigenGetMatrixValue(int _matrix_row, int _matrix_column);

    void EigenSetVectorValue(int _vector_row, double _vector_value);
    void EigenAddVectorValue(int _vector_row, double _vector_value);
    double EigenGetVectorValue(int _vector_row);

public:
    void EigenDoSolve();
    VectorXd EigenSolution();

private:
    MatrixXd EigenGetInverseMatrix();
    void EigenInverseMatrixPlusVector();

private:
    MatrixXd eigen_matrix;                    // Ax = b : A
    // MatrixXd eigen_matrix_inverse;            // Ax = b : A(-1)
    VectorXd eigen_vector;                    // Ax = b : b
    VectorXd eigen_vector_solution;           // Ax = b : x
    int matrix_row_count;
    int matrix_column_count;
    int vector_row_count;
};

#endif // MATRIXEIGEN_H