#include <iostream>
#include "MutantStack.hpp"
#include <stack>
#include <vector>
#include <algorithm>
#include <list>

void f(int const& x) {
	std::cout << x << " | " << &x << "\n";
}

void print(int x) {
	std::cout << x << std::endl;
}

int	main(int ac, char *av[]) {
	(void)ac;
	(void)av;
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

	MutantStack<int> mstack2;
	mstack2.push(666);
	mstack2.push(777);
	mstack2.push(888);
	std::cout << std::endl;
	std::for_each(mstack2.begin(), mstack2.end(), &print);
	return (0);
}
