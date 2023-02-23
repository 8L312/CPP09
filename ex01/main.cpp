#include <iostream>
#include <string>
#include <stdexcept>
#include <stack>

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac += 2)
    {
        std::cout << "Usage : \"RPM [calculation]\"\n";
        return (1);
    }
    
    RPN rpn;

    if (rpn.TakeArg(av[1]) != 0)
    {
        std::cout << "Error\n";
        return (1);
    }
    rpn.DoCalculation();
    return (0);
}