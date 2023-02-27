#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void): _Example(0)
{
	//std::cout << "Default constructor called\n";
	return ;
}

/*BitcoinExchange::BitcoinExchange(int const n): _Example(n)
{
	//std::cout << "Parametric constructor called\n";
	return ;
}*/

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
	//std::cout << "Copy constructor called\n";
	return ;
}

BitcoinExchange::~BitcoinExchange(void)
{
	//std::cout << "Destructor called\n";
	return ;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	//copy here the eventual values like :
	this->_Example = rhs.getExample();

	//std::cout << "Copy assignment operator called\n";
	return (*this);
}
