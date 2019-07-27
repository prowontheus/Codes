#include <iostream>
#include "SimpleDLLClass.h"

int main()
{
    SimpleDLLClass sdc;
    std::cout << sdc.getValue() << std::endl;
    SimpleDLLClass sdc1;
    std::cout << sdc1.getValue() << std::endl;
    return 0;
}
