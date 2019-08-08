#include "MatrixEigen.h"

MatrixEigen::MatrixEigen(int _matrix_row, int _matrix_column, int _vector_row)
{
    matrix_row_count = _matrix_row;
    matrix_column_count = _matrix_column;
    vector_row_count = _vector_row;
    eigen_matrix = MatrixXd::Zero(matrix_row_count, matrix_column_count);
    eigen_vector = VectorXd::Zero(vector_row_count);
    eigen_vector_solution = VectorXd::Zero(vector_row_count);
}

// empty
MatrixEigen::~MatrixEigen() {}

void MatrixEigen::EigenPrintMatrix()
{
    std::cout << eigen_matrix << std::endl;
}

void EigenPrintMatrixInverse()  {}

void MatrixEigen::EigenPrintVector()
{
    std::cout << eigen_vector << std::endl;
}

void MatrixEigen::EigenPrintVectorSolution()
{
    std::cout << eigen_vector_solution << std::endl;
}

void MatrixEigen::EigenAddMatrixRow(int _matrix_row_count)
{
    matrix_row_count += _matrix_row_count;
    eigen_matrix = MatrixXd::Zero(matrix_row_count, matrix_column_count);
}

void MatrixEigen::EigenAddMatrixColumn(int _matrix_column_count)
{
    matrix_column_count += _matrix_column_count;
    eigen_matrix = MatrixXd::Zero(matrix_row_count, matrix_column_count);
}

void MatrixEigen::EigenAddVectorRow(int _vector_row_count)
{
    vector_row_count +=_vector_row_count;
    eigen_vector = VectorXd::Zero(vector_row_count);
    eigen_vector_solution = VectorXd::Zero(vector_row_count);
}

void MatrixEigen::EigenSetMatrixValue(int _matrix_row, int _matrix_column, double _matrix_value)
{
    eigen_matrix(_matrix_row, _matrix_column) = _matrix_value;
}

void MatrixEigen::EigenAddMatrixValue(int _matrix_row, int _matrix_column, double _matrix_value)
{
    eigen_matrix(_matrix_row, _matrix_column) += _matrix_value;
}

double MatrixEigen::EigenGetMatrixValue(int _matrix_row, int _matrix_column)
{
    double _matrix_value = eigen_matrix(_matrix_row, _matrix_column);
    return _matrix_value;
}

void MatrixEigen::EigenSetVectorValue(int _vector_row, double _vector_value)
{
    eigen_vector(_vector_row) = _vector_value;
}

void MatrixEigen::EigenAddVectorValue(int _vector_row, double _vector_value)
{
    eigen_vector(_vector_row) += _vector_value;
}

double MatrixEigen::EigenGetVectorValue(int _vector_row)
{
    double _vector_value = eigen_vector(_vector_row);
    return _vector_value;
}

MatrixXd MatrixEigen::EigenGetInverseMatrix()
{
    MatrixXd middle_matrix = MatrixXd::Zero(matrix_row_count - 1, matrix_column_count - 1);
    for(int i = 0; i < matrix_row_count - 1; i++)
    {
        for(int j = 0; j < matrix_column_count - 1; j++)
        {
            middle_matrix(i, j) = eigen_matrix(i + 1, j + 1);
        }
    }
    return middle_matrix.inverse();   
}

void MatrixEigen::EigenInverseMatrixPlusVector()
{
    EigenPrintMatrix();
    EigenPrintVector();
    VectorXd eigen_middle_vector = VectorXd::Zero(vector_row_count - 1);
    for(int i = 0; i < vector_row_count - 1; i++)
    {
        eigen_middle_vector(i) = eigen_vector(i + 1);
    }
    VectorXd middle_solution = EigenGetInverseMatrix() * eigen_middle_vector;
    // eigen_vector_solution(0) = 0.0;
    for(int i = 1; i < vector_row_count; i++)
    {
        eigen_vector_solution(i) = eigen_middle_vector(i - 1);
    }
}

void MatrixEigen::EigenDoSolve()
{
    EigenInverseMatrixPlusVector();
}

VectorXd MatrixEigen::EigenSolution()
{
    return eigen_vector_solution;
}
