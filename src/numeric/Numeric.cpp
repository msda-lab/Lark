#include "Numeric.h"

Numeric::Numeric()  {}

Numeric::Numeric(int _node_count, int _analysis_type, int _default_value = 0)
{
    numeric_matrix = new MatrixEigen(_node_count, _node_count);
}

Numeric::~Numeric() {}

// empty
void Numeric::ResetMatrix(double _value)
{}

// empty
void Numeric::ResetRHS(double _value)
{}

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
void Numeric::AddMatrixRow(int _row_count)
{}

// empty
void Numeric::AddMatrixColumn(int _column_count)
{}