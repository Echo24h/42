#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(int ac, char *av[]) {
	ShrubberyCreationForm	xx("target");
	Bureaucrat				me("yo", 150);

	xx.execute(me);
	//xx = ShrubberyCreationForm("test");
	//std::cout << xx.getName() << std::endl;
	return (0);
}
