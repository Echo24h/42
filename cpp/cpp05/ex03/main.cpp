#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main(int ac, char *av[]) {
	try {
		Bureaucrat me("yo", 50);
		Intern mm;

		Form * f = mm.makeForm("shrubbery creation", "lol");
		f->beSigned(me);
		me.executeForm(*f);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
