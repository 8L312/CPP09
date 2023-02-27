#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if 	(ac != 2)
	{
		std::cout << "Usage: \"./btc [filename.txt]\"\n";
		return (1);
	}

	BitcoinExchange	btc("data.csv");
	if ( btc.init(av[1]) == 1 )
		return (1);
	else
		return (btc.output());
}
