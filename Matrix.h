#pragma once
class Matrix
{
private:
    int rows;
    int columns;
    int** matrix;
    void swap(const int&, const int&);
public:
    Matrix(const int&, const int&);
    Matrix(const Matrix&);
    Matrix(Matrix&&) noexcept;

    Matrix& operator=(Matrix&&) noexcept;
    Matrix& operator+(const Matrix&);
    Matrix& operator=(const Matrix&);
    ~Matrix();
    Matrix& operator++();
    Matrix operator++(int);

    void populate() const;
    void print() const;
    void transpose();
};

