#include <iostream>
#include "Array.hpp"
#include <iomanip>

int	main(int ac, char *av[]) {
	(void)ac;
	(void)av;
	//std::cout << std::setprecision(38) << __FLT_MAX__ << std::endl;
	Array<int> tab;
	std::cout << tab << std::endl;
	return (0);
}
