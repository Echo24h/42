#include <iostream>
#include "Bureaucrat.hpp"

int	main(int ac, char *av[]) {
	Bureaucrat	p1("john", 150);
	std::cout << p1 << std::endl;
	try {
		p1.decrGrade();
		std::cout << p1 << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << p1 << std::endl;
	return (0);
}
