#include <iostream>
#include "Increment.h"
#include "Matrix.h"
int main()
{
    Matrix mat1(3, 3);
    mat1.populate();
    std::cout << "Matrix 1 (mat1):" << std::endl;
    mat1.print();

    Matrix mat2(std::move(mat1));
    std::cout << "Matrix 2 (moved from mat1):" << std::endl;
    mat2.print();
    std::cout << "Matrix 1 after move:" << std::endl;
    mat1.print();

    Matrix mat3(3, 3);
    mat3 = std::move(mat2);
    std::cout << "Matrix 3 (moved from mat2):" << std::endl;
    mat3.print();
    std::cout << "Matrix 2 after move:" << std::endl;
    mat2.print();

    return 0;

}
