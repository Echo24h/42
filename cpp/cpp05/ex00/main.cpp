#include <iostream>
#include "Bureaucrat.hpp"

int	main(int ac, char *av[]) {
	
	(void)ac;
	(void)av;
	try {
		Bureaucrat	p1("john", 0);
		std::cout << p1 << std::endl;
		p1.decrGrade();
		std::cout << p1 << std::endl;
	} catch (Bureaucrat::GradeTooLowException & e) {
		std::cout << e.what() << std::endl;
	} catch (std::exception & e) {
		std::cout << "here: " << e.what() << std::endl;
	}
	system("leaks prog | grep leaked");
	return (0);
}
