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
	
	i = 0;
	clock_t start = clock();

	while (av[++i] != NULL)
		_set.insert( std::atoi(av[i]) );

	clock_t end = clock();
	_timeSet = (end - start) / static_cast<double>(CLOCKS_PER_SEC);
}

void	PmergeMe::sortValues(void)
{
	clock_t	start;
	clock_t	end;

	//	LIST SORTING //
	start = clock();
	_list.sort();
	end = clock();

	_timeList = (end - start) / static_cast<double>(CLOCKS_PER_SEC);

	// VECTOR SORTING //
	start = clock();
	std::sort( _vector.begin(), _vector.end() );
	end = clock();

	_timeVector = (end - start) / static_cast<double>(CLOCKS_PER_SEC);
}

void	PmergeMe::sortVector(void)
{
	std::vector<unsigned int>	tmp;
	clock_t						start;
	clock_t						end;

	start = clock();

	tmp.push_back(_vector.back());
	_vector.pop_back();
	while ( !_vector.empty() )
	{
		std::vector<unsigned int>::iterator	Itmp = tmp.begin();
		while (_vector.back() >= *Itmp && Itmp != tmp.end())
			Itmp++;
		tmp.insert( Itmp, _vector.back() );
		_vector.pop_back();
	}
	_vector = tmp;

	end = clock();
	_timeVector = (end - start) / static_cast<double>(CLOCKS_PER_SEC);
}

void	PmergeMe::sortList(void)
{
	std::list<unsigned int>	tmp;
	clock_t					start;
	clock_t					end;

	start = clock();
	tmp.push_back(_list.back());
	_list.pop_back();
	while ( !_list.empty() )
	{
		std::list<unsigned int>::iterator	Itmp = tmp.begin();
		while (_list.back() >= *Itmp && Itmp != tmp.end())
			Itmp++;
		tmp.insert( Itmp, _list.back() );
		_list.pop_back();
	}
	_list = tmp;

	end = clock();
	_timeList = (end - start) / static_cast<double>(CLOCKS_PER_SEC);
}

void	PmergeMe::displayResults(void)
{
	std::cout << "After  : ";
	int i = 0;
	for (std::vector<unsigned int>::iterator it = _vector.begin();
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

	std::cout << "Time to process a range of " << _vector.size()
		<< " elements with std::vector : " << std::fixed
		<< _timeVector * 1000000  << " us" << std::endl;

	std::cout << "Time to process a range of " << _list.size()
		<< " elements with std::list   : " << std::fixed
		<< _timeList * 1000000 << " us" << std::endl;


	std::cout << "Time to process a range of " << _set.size()
		<< " elements with std::set    : " << std::fixed
		<< _timeSet * 1000000 << " us" << std::endl;
}
