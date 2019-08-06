#ifndef NUMERIC_H
#define NUMERIC_H

#define EIGENCHOSEN 1

#include "MatrixEigen.h"

#include "../include/eigen/Core"
#include "../include/eigen/Dense"

#include <iostream>

using namespace Eigen;
using namespace std;

class Numeric
{
public:
    Numeric();
    Numeric(int _node_count, int _analysis_type);
    ~Numeric();
    void Destroy(); // Let us destroy all the world!

// Ax = b : Matrix A
public:
    void ResetMatrix();
    void ResetVector();

// Ax = b : Matrix A
    void GetSolution();

// Ax = b : Matrix A
// operation on matrix

    // structure
    void AddMatrixRow(int _row_count);
    void AddMatrixColumn(int _column_count);
    void AddVectorRow(int _row_count);

    // elements
    double GetMatrixValue(int _row, int _column);
    void SetMatrixValue(int _row, int _column, double _value);
    void AddMatrixValue(int _row, int _column, double _value);

// Ax = b : Vector b
    double GetVectorValue(int _row);
    void SetVectorValue(int _row, double _value);
    void AddVectorValue(int _row, double _value);

    int GetDimension() const;
    void AddDimension(int _dimension);

    void PrintMatrix() const;
    void PrintVector() const;

private:
    int analysis_type;      // Analysis Type : DC = 1000 .etc
    int dimension;

#if 1
    MatrixEigen *numeric_matrix;
#endif

    VectorXd *numeric_vector;
};

#endif // NUMERIC_H
