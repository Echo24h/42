#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <stack>
#include "easyfind.hpp"

int	main(int ac, char *av[]) {
	(void)ac;
	(void)av;
	std::stack<int> v;
	v.push(5);
	v.push(3);
	v.push(8);
	v.push(1);
	try {
		int x = easyfind(v, 8);
		std::cout << x << std::endl;
	} catch (std::runtime_error & e) {
		std::cout << e.what() << std::endl;
	}
}
