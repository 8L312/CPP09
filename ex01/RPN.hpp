#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <stack>

class RPN {
public:
    RPN(RPN &src);
    ~RPN(void);

    void    TakeArg(char *str);
    void    DoCalculation(void);

    RPN &operator=(RPN const &rhs);

private:
    RPN(void);
    
    std::stack<char>  _stack;


};

#endif