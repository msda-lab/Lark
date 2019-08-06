#include "Numeric.h"

Numeric::Numeric()
{
}

Numeric::Numeric(int _node_count, int _analysis_type, int _default_value)
{
    numeric_matrix = new MatrixEigen(_node_count, _node_count);
    numeric_vector = new VectorXd(_node_count); 
    analysis_type = _analysis_type;
    dimension = _node_count;
}

Numeric::~Numeric()
{
}

void Numeric::Destroy()
{

}

void Numeric::GetSolution()
{

}

int Numeric::GetDimension() const
{
    return dimension;
}

void Numeric::AddDimension(int _dimension)
{
    dimension += _dimension;
}

// empty
void Numeric::ResetMatrix(double _value)
{
}

// empty
void Numeric::ResetVector(double _value)
{
}

// empty
void Numeric::AddMatrixRow(int _row_count)
{
}

// empty
void Numeric::AddMatrixColumn(int _column_count)
{
}

double Numeric::GetMatrixValue(int _row, int _column)
{
    return numeric_matrix->GetValue(_row, _column);
}

void Numeric::SetMatrixValue(int _row, int _column, double _value)
{
    numeric_matrix->SetValue(_row, _column, _value);
}

void Numeric::AddMatrixValue(int _row, int _column, double _value)
{
    numeric_matrix->AddValue(_row, _column, _value);
}

// empty
void Numeric::AddVectorRow(int _row_count)
{

}

// empty
double Numeric::GetVectorValue(int _row)
{
    return 0;

}

// empty
void Numeric::SetVectorValue(int _row, double _value)
{

}

// empty
void Numeric::AddVectorValue(int _row, double _value)
{

}

