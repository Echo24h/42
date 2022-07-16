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
	std::vector<int> v;
	v.push_back(5);
	v.push_back(3);
	v.push_back(8);
	v.push_back(1);
	try {
		int x = easyfind(v, 5);
		std::cout << x << std::endl;
	} catch (std::runtime_error & e) {
		std::cout << e.what() << std::endl;
	}
}
