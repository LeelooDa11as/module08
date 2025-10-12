#include "easyfind.hpp"

void	test_vector(void) {
	std::vector<int>	test;
	int					num = 10;
	for (int i = 0; i < 10; i++) {
		test.push_back(num);
		num++;
	}

	for (int i = 0; i < 10; i++) {

		std::cout << "index: " << i << " valor: " << test[i] << std::endl;
	}

	try {
		easyfind(test, 15);
		easyfind(test, 1);
	}

	catch (const char* e) {
		std::cout << "Error: " << e << std::endl;
	}
	return;
}


int	main(void) {
	//test_list();
	test_vector();
	//test_deque();
	return 0;
}