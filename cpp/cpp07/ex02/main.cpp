#include <iostream>
#include "Array.hpp"

int	main(int ac, char *av[]) {
	(void)ac;
	(void)av;

	Array<int> tab(7);
	std::cout << tab << std::endl;
	return (0);
}
