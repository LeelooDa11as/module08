#include "Span.hpp"
#include <ctime>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

void	test1(void)
{
	std::cout << BLUE << "---------- Simple test: addNumber and Max & Min Span ----------\n" << RESET << std::endl;
	
	Span	test(7);
	test.addNumber(-1);
	test.addNumber(10);
	test.addNumber(56);
	test.addNumber(9);
	test.addNumber(18);
	test.addNumber(8);
	test.addNumber(-13);
	std::cout << "Max span is: " << test.longestSpan() << std::endl;
	std::cout << "Min span is: " << test.shortestSpan() << std::endl;

	try {
		test.addNumber(6);
	}

	catch (const char *err_msg) {
		std::cout << RED << err_msg << RESET <<std::endl; 
	}

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	return;
}

void test2(void)
{
	std::cout << BLUE << "---------- Exception test: not enough elements ----------\n" << RESET << std::endl;

	Span empty(5);
	try {
		std::cout << empty.shortestSpan() << std::endl;
	} catch (const char *e) {
		std::cout << RED << e << RESET << std::endl;
	}

	empty.addNumber(42);
	try {
		std::cout << empty.longestSpan() << std::endl;
	} catch (const char *e) {
		std::cout << RED << "Expected error: " << e << RESET << std::endl;
	}

	return;
}


void	test3(void)
{
	std::cout << BLUE << "---------- Using different types of containers ----------\n" << RESET << std::endl;

	Span	arr_test(12000);
	std::vector<int> big_boy;

	for (int i = 0; i < 13000; i++) {
		big_boy[i] = rand();
	}
	arr_test.addNumbers(big_boy.begin()+2000, big_boy.end());
	std::cout << arr_test.shortestSpan() << std::endl;
	std::cout << arr_test.longestSpan() << std::endl;

	std::list<int>	small_boy;
	for (int i = 0; i < 1000; i++)
		small_boy.push_front(rand());

	arr_test.addNumbers(small_boy.begin(), small_boy.end());
	std::cout << arr_test.shortestSpan() << std::endl;
	std::cout << arr_test.longestSpan() << std::endl;

	std::cout << BLUE << "\n---------- Using different types of containers ----------\n" << RESET << std::endl;



	return;
}

int	main(void) {
	srand(time(NULL));
	test1();
	test2();
	test3();
	return (0);
}