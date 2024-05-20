#include "Matrix.h"
#include <stdexcept>
#include <iostream>

Matrix::Matrix(const int& p_rows, const int& p_cols) : rows(p_rows), columns(p_cols) {
    matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
    }
}

Matrix::Matrix(const Matrix& m) {
    rows = m.rows;
    columns = m.columns;
    matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = m.matrix[i][j];
        }
    }
}

Matrix::Matrix(Matrix&& obj) noexcept : rows(obj.rows), columns(obj.columns), matrix(obj.matrix) {
    obj.rows = 0;
    obj.columns = 0;
    obj.matrix = nullptr;
    std::cout << "moved" << std::endl;
}

Matrix& Matrix::operator=(Matrix&& obj) noexcept {
    if (this != &obj) {
        rows = obj.rows;
        columns = obj.columns;
        matrix = obj.matrix;
        std::cout << "moved = " << std::endl;

        obj.rows = 0;
        obj.columns = 0;
        obj.matrix = nullptr;
    }
    return *this;
}

Matrix& Matrix::operator+(const Matrix& m) {
    if (rows != m.rows || columns != m.columns) {
        throw std::logic_error("Cannot add two matrices with varied column or row sizes");
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] += m.matrix[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator=(const Matrix& m) {
    if (this != &m) {
        if (matrix != nullptr) {
            for (int i = 0; i < rows; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
        rows = m.rows;
        columns = m.columns;
        matrix = new int* [rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[columns];
            for (int j = 0; j < columns; j++) {
                matrix[i][j] = m.matrix[i][j];
            }
        }
    }
    return *this;
}

Matrix::~Matrix() {
    if (matrix != nullptr) {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}

Matrix& Matrix::operator++()
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = matrix[i][j] + 3;
        }
    }

    return *this;
}

Matrix Matrix::operator++(int)
{
    Matrix temp(*this);
    ++(*this);
    
    return temp;
}

void Matrix::populate() const {
    int counter = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = counter++;
        }
    }
}

void Matrix::print() const {
    if (matrix == nullptr)
    {
        std::cout << "Matrix is empty" << std::endl;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << "[" << i << "][" << j << "]: " << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void Matrix::transpose() {
    if (rows != columns) {
        throw std::logic_error("Cannot transpose the matrix when rows and columns are not equal");
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < i; j++) {
            swap(i, j);
        }
    }
}

void Matrix::swap(const int& x, const int& y) {
    int temp = matrix[x][y];
    matrix[x][y] = matrix[y][x];
    matrix[y][x] = temp;
}
