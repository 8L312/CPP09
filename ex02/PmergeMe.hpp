#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <stdexcept>
# include <ctime>
# include <list>
# include <vector>
#include <algorithm>

# define MAXDISPLAY 10

class PmergeMe
{

public:
	PmergeMe(void);
	PmergeMe(PmergeMe const &src);
	~PmergeMe(void);

	void	takeArg(char **av);
	void	sortValues(void);
	void	displayResults(void);

	PmergeMe	&operator=(PmergeMe const &rhs);

private:
	std::vector<unsigned int>	_vector;
	std::list<unsigned int>		_list;
	double		_timeVector;
	double		_timeList;

};

#endif
