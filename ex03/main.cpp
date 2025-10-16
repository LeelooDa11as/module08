#include "MutantStack.hpp"
#include <stack>
#include <iostream>


void	constructor_test() {

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(10);

    std::cout << "Top: " << mstack.top() << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;
	
    mstack.pop();
    std::cout << "Top after pop: " << mstack.top() << std::endl; // Should print 5
    std::cout << "Size after pop: " << mstack.size() << std::endl; // Should print 1

    mstack.push(20);
    mstack.push(30);
    std::cout << "Forward iteration: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " "; // 5 20 30
    std::cout << std::endl;

    std::cout << "Reverse iteration: ";
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
        std::cout << *rit << " "; // 30 20 5
    std::cout << std::endl;

    MutantStack<int> copy(mstack);
    std::cout << "Copy top: " << copy.top() << std::endl; // 30

    MutantStack<int> assigned;
    assigned = mstack;
    std::cout << "Assigned top: " << assigned.top() << std::endl; //30

    return ;
}


void	test_vector(void) {
    MutantStack<int, std::vector<int> > mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	// to work with other type of container put its full iterator
	MutantStack<int, std::vector<int> >::iterator it = mstack.begin();
	MutantStack<int, std::vector<int> >::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int, std::vector<int> > s(mstack);
	std::cout << "Size of the original is: " << mstack.size() << std::endl;
	std::cout << "Size of the copy is: " << s.size() << std::endl;
	return;
}

void	test_with_list(void) {
    std::list<int> mstack;

    mstack.push_back(5);
    mstack.push_back(17);
    std::cout << mstack.back() << std::endl;
    mstack.pop_back();
    std::cout << mstack.size() << std::endl;
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);

    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    return;
}

void	test_from_module(void) {
    MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	return;
}

int main()
{
	//test_with_list();
	std::cout << "---------------------------------" << std::endl;
	//test_from_module();
	std::cout << "---------------------------------" << std::endl;
	//test_vector();
	std::cout << "---------------------------------" << std::endl;
	constructor_test();
	return 0;
}