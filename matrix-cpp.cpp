#include <iostream>
#include "Increment.h"
#include "Matrix.h"
int main()
{
    Increment obj, obj1;
    obj.print("obj");
    obj1.print("obj1");

    obj1 = ++obj;
    obj.print("obj");
    obj1.print("obj1");

    obj1 = obj++;
    obj.print("obj");
    obj1.print("obj1");

    Matrix matrix(2, 2);

    matrix.populate();

    std::cout << "Original matrix:" << std::endl;
    matrix.print();

    ++matrix;
    std::cout << "After prefix increment:" << std::endl;
    matrix.print();

    Matrix old = matrix++;
    std::cout << "Old matrix after postfix increment:" << std::endl;
    old.print();
    std::cout << "Current matrix after postfix increment:" << std::endl;
    matrix.print();

    return 0;

}
