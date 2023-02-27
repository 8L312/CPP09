#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <stdexcept>
# include <fstream>

class BitcoinExchange
{

public:
	BitcoinExchange(char *data); //data will b given in .csv format
	BitcoinExchange(BitcoinExchange const &src);
	~BitcoinExchange(void);

//	AAA;

	BitcoinExchange	&operator=(BitcoinExchange const &rhs);

private:
	BitcoinExchange(void);
	std::map<std::string date, float value>	btvalue;

	

};

#endif
