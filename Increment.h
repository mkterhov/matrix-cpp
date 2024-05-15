#pragma once
#include <iostream>

class Increment
{
private:
	int i = 0;
public:
    Increment& operator ++ ()
    {
        std::cout << "prefix operator " << std::endl;
        i = i + 1;
        return *this;
    }

    Increment operator ++ (int)
    {
        Increment temp = *this;
        std::cout << "postfix operator " << std::endl;
        i++;
        return temp;
    }

    void print(std::string objName)
    {
        std::cout << objName << ":" << "i = " << i << std::endl;
    }
};

