#include "easyfind.hpp"

template< typename T>
void	printContainer(T const container) {
	for (typename T::const_iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " " << std::endl;
	return;
}

void	test_list(void) {
	std::list<int>	test(2, 17);
	int				num = -4;
	std::list<int>::iterator it = test.begin();
	std::advance(it, 1); // to access any index, no [] as lists are linked
	test.insert(it, 2, 5);
	for (int i = 0; i < 3; i++) {
		test.push_back(num);
		num++;
	}
	test.push_front(33);
	printContainer(test);
	try {
		std::list<int>::iterator it_1 = easyfind(test, 5);
		std::cout << *it_1 << " was found" << std::endl;
		std::list<int>::iterator	it_2 = easyfind(test, 1);
		std::cout << *it_2 << " was found" << std::endl;
	}
	catch(const char* e)
	{
		std::cerr << "Error: " << e << std::endl;
	}
}

void	test_vector(void) {
	std::vector<int>	test(3, 5);
	test.insert(test.begin() + 1, 2, 25);
	int					num = 10;
	for (int i = 0; i < 5; i++) {
		test.push_back(num);
		num++;
	}
	test[9] = -8;
	printContainer(test);
	try {
		std::vector<int>::iterator it_1 = easyfind(test, 5);
		std::cout << *it_1 << " was found" << std::endl;
		std::vector<int>::iterator	it_2 = easyfind(test, 1);
		std::cout << *it_2 << " was found" << std::endl;
	}

	catch (const char* e) {
		std::cout << "Error: " << e << std::endl;
	}
	return;
}

void	test_deque(void) {
	std::deque<int>	test(2, 14);
	test.insert(test.end()-1, 2, 48);
	test.push_front(10);
	test.push_back(3);
	printContainer(test);
	try {
		std::deque<int>::iterator it_1 = easyfind(test, 48);
		std::cout << *it_1 << " was found" << std::endl;
		std::deque<int>::iterator	it_2 = easyfind(test, 9);
		std::cout << *it_2 << " was found" << std::endl;
	}

	catch (const char* e) {
		std::cout << "Error: " << e << std::endl;
	}
	return;
}

int	main(void) {
	//test_list();
	//test_vector();
	test_deque();
	return 0;
}