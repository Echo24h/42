#include <iostream>
#include "iter.hpp"

template<typename T>
void print(T val) {
    std::cout << val << std::endl;
}

int	main(int ac, char *av[]) {
	(void)ac;
	(void)av;
	int x[] = {1, 8, 9, 6};
	iter(x, 4, &print);
	std::cout << std::endl;

	std::string z[] = {"nul", "prout", "abc0", "zzz"};
	iter(z, 4, &print);
	std::cout << std::endl;
	return (0);
}
