#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(int ac, char *av[]) {
	try {
		Form	ff("myForm", 50, 70);
		Bureaucrat	p1("john", 51);
		
		std::cout << p1 << std::endl;
		p1.signForm(ff);
		std::cout << ff << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}
