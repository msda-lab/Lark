#include "Numeric.h"

Numeric::Numeric()
{
}

Numeric::Numeric(int _node_count, int _analysis_type, int _default_value)
{
    numeric_matrix = new MatrixEigen(_node_count, _node_count);
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

// empty
void Numeric::ResetMatrix(double _value)
{
}

// empty
void Numeric::ResetRHS(double _value)
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

}

// empty
void Numeric::SetVectorValue(int _row, double _value)
{

}

// empty
void Numeric::AddVectorValue(int _row, double _value)
{

}


