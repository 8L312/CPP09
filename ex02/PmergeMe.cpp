#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	//std::cout << "Default constructor called\n";
	return ;
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
	//std::cout << "Copy constructor called\n";
	return ;
}

PmergeMe::~PmergeMe(void)
{
	//std::cout << "Destructor called\n";
	return ;
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &rhs)
{
	//copy here the eventual values like :
	this->_list = rhs._list;
	this->_vector = rhs._vector;

	//std::cout << "Copy assignment operator called\n";
	return (*this);
}

void	PmergeMe::takeArg(char **av)
{
	int i = 0;
	while (av[++i] != NULL)
	{
		_vector.push_back( std::atoi(av[i]) );
		_list.push_back( std::atoi(av[i]) );
	}
}

void	PmergeMe::sortValues(void)
{
	clock_t	start;
	clock_t	end;

	//	LIST SORTING //
	start = clock();
	_list.sort();
	end = clock();

	_timeList = (end - start) / (double)CLOCKS_PER_SEC;

	// VECTOR SORTING //
	start = clock();
	std::sort( _vector.begin(), _vector.end() );
	end = clock();

	_timeVector = (end - start) / (double)CLOCKS_PER_SEC;
}

void	PmergeMe::displayResults(void)
{
	std::cout << "After  : ";
	int i = 0;
	for (std::vector<unsigned int>::iterator it=_vector.begin();
			it!=_vector.end(); ++it)
	{
    	std::cout << *it << " ";
		if (++i > MAXDISPLAY)
		{
			std::cout << "[...]";
			break ;
		}
	}
  	std::cout << '\n';

	std::cout << "Time to process a range of " << _list.size()
		<< " elements with std::list : " << std::fixed
		<< _timeList * 1000000 << " us" << std::endl;
	
	std::cout << "Time to process a range of " << _vector.size()
		<< " elements with std::vector : " << std::fixed
		<< _timeVector * 1000000 << " us" << std::endl;
}
