#include <iostream>
#include <string>
#include <stdexcept>
#include <stack>

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage : \"RPM [calculation]\"\n";
        return (1);
    }

    RPN rpn;
    rpn.DoCalculation(av[1]);
    return (0);
}
