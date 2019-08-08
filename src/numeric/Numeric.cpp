#include "Numeric.h"

Numeric::Numeric()  {}

Numeric::Numeric(int _node_count, int _analysis_type)
{
    numeric_matrix = new MatrixEigen(_node_count, _node_count, _node_count);
    // numeric_vector = new VectorXd(_node_count); 
    analysis_type = _analysis_type;
    dimension = _node_count;
}

Numeric::~Numeric()
{
    delete numeric_matrix;
}

void Numeric::Destroy()
{
    std::cout << "Destroy!" << std::endl;
}

std::vector<double> Numeric::GetSolution()
{
    numeric_matrix->EigenDoSolve();
    VectorXd middle_vector = numeric_matrix->EigenSolution();
    int size = middle_vector.size();
    std::vector<double> solution_vector;
    for(int i = 0; i < size; i++)
    {
        solution_vector.push_back(middle_vector(i));
    }
    return solution_vector;
}

int Numeric::GetDimension() const
{
    return dimension;
}

void Numeric::AddDimension(int _dimension)
{
    dimension += _dimension;
    numeric_matrix->EigenAddMatrixColumn(_dimension);
    numeric_matrix->EigenAddMatrixRow(_dimension);
    numeric_matrix->EigenAddVectorRow(_dimension);
}

void Numeric::ResetMatrix()     // reset to zero
{
    numeric_matrix->EigenAddMatrixColumn(0);
}

void Numeric::ResetVector()     // reset to zero
{
    numeric_matrix->EigenAddVectorRow(0);
}

void Numeric::AddMatrixRow(int _row_count)
{
    numeric_matrix->EigenAddMatrixRow(_row_count);
}

void Numeric::AddMatrixColumn(int _column_count)
{
    numeric_matrix->EigenAddMatrixColumn(_column_count);
}

double Numeric::GetMatrixValue(int _row, int _column)
{
    return numeric_matrix->EigenGetMatrixValue(_row, _column);
}

void Numeric::SetMatrixValue(int _row, int _column, double _value)
{
    numeric_matrix->EigenSetMatrixValue(_row, _column, _value);
}

void Numeric::AddMatrixValue(int _row, int _column, double _value)
{
    numeric_matrix->EigenAddMatrixValue(_row, _column, _value);
}

void Numeric::AddVectorRow(int _row_count)
{
    numeric_matrix->EigenAddVectorRow(_row_count);
}

double Numeric::GetVectorValue(int _row)
{
    return numeric_matrix->EigenGetVectorValue(_row);
}

void Numeric::SetVectorValue(int _row, double _value)
{
    numeric_matrix->EigenSetVectorValue(_row, _value);
}

void Numeric::AddVectorValue(int _row, double _value)
{
    numeric_matrix->EigenAddVectorValue(_row, _value);
}

void Numeric::PrintMatrix() const
{
    numeric_matrix->EigenPrintMatrix();
}

void Numeric::PrintVector() const
{
    numeric_matrix->EigenPrintVector();
}

