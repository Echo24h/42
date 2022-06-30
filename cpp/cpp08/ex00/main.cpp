#include <iostream>
#include <vector>
#include "easyfind.hpp"

int	main(int ac, char *av[]) {
	(void)ac;
	(void)av;
	std::vector<int> v;
	v.push_back(5);
	v.push_back(3);
	v.push_back(8);
	v.push_back(1);
	int x = easyfind(v, 3);
	std::cout << x << std::endl;
	return (0);
}
