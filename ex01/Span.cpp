#include "Span.hpp"

Span::Span(void) : N(0){
	std::cout << "Span class default constructor called" << std::endl;
}

Span::Span(unsigned int N) : N(N){
	std::cout << "Span class full constructor called" << std::endl;
}

Span::Span(const Span &other) : N(other.N), vector(other.vector){
	std::cout << "Span class copy constructor called" << std::endl;
}

Span&	Span::operator=(const Span &other) {
	std::cout << "Span class assignment operator called" << std::endl;
	if (this != &other) {
		this->N = other.N;
		vector.clear();
		for (unsigned int i = 0; i < N; i++)
			vector.push_back(other.vector[i]);
	}
	return *this;
}

Span::~Span(void) {
	std::cout << "Span class destructor called" << std::endl;
}

void	Span::addNumber(int num) {
	if (vector.size() >= N)
		throw ("Error: Vector is full");
	vector.push_back(num);
	return;
}

int		Span::shortestSpan(void) const {
	if(vector.size() <= 1)
		throw("Error: not enough elements in the vector");
	std::vector<int> sorted = vector;
	std::sort(sorted.begin(), sorted.end());

	int shortest = std::numeric_limits<int>::max();

	for (size_t i = 1; i < sorted.size(); i++) {
    	int diff = sorted[i] - sorted[i - 1];
    	if (diff < shortest)
        	shortest = diff;
}
	return shortest;
}

int		Span::longestSpan(void) const {
	if(vector.size() <= 1)
		throw("Error: not enough elements in the vector");
	std::vector<int>::const_iterator	start = vector.begin();
	std::vector<int>::const_iterator	end = vector.end();
	int	min = *(std::min_element(start, end));
	int	max = *(std::max_element(start, end));
	return (max - min);


	// iteration version
	/*int min = vector[0];
	int	max = vector[0];
	for (size_t i = 0; i < vector.size(); i++) {
		if (max < vector[i])
			max = vector[i];
		if (min > vector[i])
			min = vector[i];
	}
	int res = max - min;
	return res;*/
}
