#include "RPN.hpp"

static int  ValidChar(char c, int elem, int i)
{
    if (i == 0)
    {
        if (/*pas un chiffre*/) // ICIIIIIIIIIIIIIIIIIIIIIII
    }
}

int    RPN::TakeArg(char *str)
{
    int i = 0;
    int elem = 1;
    while (av[i] != NULL)
        i++;
    i--;
    while (i >= 0)
    {
        if (str[i] == ' ')
            i--;
        else
        {
            if (validchar(str[i], elem, i) != 0)
                return (1);
            this->_stack.push(str[i--]);
        }
    }
}