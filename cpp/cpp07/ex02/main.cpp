#include <iostream>
#include "Array.hpp"

int	main(int ac, char *av[]) {
	(void)ac;
	(void)av;

	Array<int> tab(7);
	std::cout << tab << std::endl;

	tab[5] = 6;
	std::cout << tab << std::endl;

	try {
		tab[8] = 7;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
