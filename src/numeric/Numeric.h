#ifndef NUMERIC_H
#define NUMERIC_H

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
    Numeric(int _node_count, int _default_value);
    ~Numeric();

public:
    void ResetMatrix(double _value = 0);
    void ResetRHS(double _value);

public:
    void AddRow(int _row_count);
    void AddColumn(int _column_count);

private:
    int analysis_type;      // Analysis Type : DC = 1000 .etc
    int matrix_dimension;
    VectorXd RHS;
    MatrixXd matrix;
};

#endif // NUMERIC_H
