#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <stdexcept>
# include <ctime>
# include <list>
# include <vector>
# include <set>
#include <algorithm>

# define MAXDISPLAY 20

class PmergeMe
{

public:
	PmergeMe(void);
	PmergeMe(PmergeMe const &src);
	~PmergeMe(void);

	void	takeArg(char **av);
	void	sortValues(void);
	void	sortVector(void);
	void	sortList(void);
	void	displayResults(void);

	PmergeMe	&operator=(PmergeMe const &rhs);

private:
	std::vector<unsigned int>	_vector;
	std::list<unsigned int>		_list;
	std::set<unsigned int>		_set;
	double		_timeVector;
	double		_timeList;
	double		_timeSet;

};

#endif
