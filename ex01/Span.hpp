#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <limits>

class	Span {
	private:
		unsigned int	N;
		std::vector<int>	vector;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span&	operator=(const Span &other);
		~Span(void);
		
		// for theory learning purpouses
		//typedef std::vector<int> container;          // shorthand for the vector itself
		//typedef container::iterator iterator;        // normal iterator
		//typedef container::const_iterator const_iterator; // const iterator

		void	addNumber(int num);

			template<typename T>
		void addNumbers(T start, T end)
		{
			size_t passed_container_size = std::distance(start, end);
			if(passed_container_size == 0)
				throw("Error: Passed container is empty");
			if(vector.size() == N)
				throw("Error: Container is already full!");
			if((N == 0) || (N - vector.size() < passed_container_size))
				throw("Error: Not enough space!");
			vector.insert(this->vector.end(), start, end);
		}
		int		shortestSpan(void) const;
		int		longestSpan(void) const;
};

/* valid InputIterators:
int*	Pointer	Works as an iterator over an array
std::vector<int>::iterator	STL iterator	Works for vectors
std::list<int>::iterator	STL iterator	Works for lists
std::deque<int>::iterator	STL iterator	Works for deques
std::istream_iterator<int>	Stream iterator	Reads numbers from input */