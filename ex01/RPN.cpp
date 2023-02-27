#include "RPN.hpp"

RPN::RPN(void)
{
	//std::cout << "Default constructor called\n";
	return ;
}

RPN::RPN(RPN const &src)
{
	*this = src;
	//std::cout << "Copy constructor called\n";
	return ;
}

RPN::~RPN(void)
{
	//std::cout << "Destructor called\n";
	return ;
}

RPN	&RPN::operator=(RPN const &rhs)
{
	//std::cout << "Copy assignment operator called\n";
	this->_stack = rhs._stack;
	return (*this);
}

static int InvalidChar(char c)
{
	if ( c == 42 || c == 43 || c == 45 || c == 47 || (48 <= c && c < 58) )
		return (0);
	return (1);
}

static void Error(void)
{
	std::cout << "Error\n";
	std::exit(1);
}

void	RPN::DoCalculation(char *av)
{
	int i = 0;
	while (av[i])
	{
		if ( av[i] == ' ' )
		{
			i++;
			continue ;
		}
		if ( InvalidChar(av[i]) )
		{
			std::cout << "Bad input in calculation\n";
			return ;
		}
		if ( 48 <= av[i] && av[i] < 58 )
		{
			_stack.push( (av[i] - 48) );
			i++;
		}
		else
		{
			if ( _stack.empty() )
				Error();

			float	tmp = _stack.top();
			float	result;

			switch(av[i])
			{
				case 42:
					_stack.pop();
					if ( _stack.empty() )
						Error();
					result = _stack.top() * tmp;
					_stack.pop();
					_stack.push(result);
					i++;
					continue ;

				case 43:
					_stack.pop();
					if ( _stack.empty() )
						Error();
					tmp += _stack.top();
					_stack.pop();
					_stack.push(tmp);
					i++;
					continue ;

				case 45:
					_stack.pop();
					if ( _stack.empty() )
						Error();
					result = _stack.top() - tmp;
					_stack.pop();
					_stack.push(result);
					i++;
					continue ;

				case 47:
					_stack.pop();
					if ( _stack.empty() )
						Error();
					if ( tmp == 0 )
					{
						std::cout << "Cannot divide by 0: ";
						Error();
					}
					result = _stack.top() / tmp;
					_stack.pop();
					_stack.push(result);
					i++;
					continue ;
			}
		}
	}
	std::cout << "Final result = " << _stack.top() << std::endl;
	
	_stack.pop();
	if ( !_stack.empty() )
		std::cout << "By the way you have extra number(s) unused ¯\\_(ツ)_/¯\n";
}
