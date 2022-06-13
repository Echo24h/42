#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(int ac, char *av[]) {
	ShrubberyCreationForm	xx("target");
	Bureaucrat				me("yo", 6);
	PresidentialPardonForm	mdr("abdoul");
	Intern					pp;
	
	me.executeForm(mdr);
	Form * form = pp.makeForm("shrubbery creation", "test");
	if (form)
		form->execute(me);
	//xx = ShrubberyCreationForm("test");
	//std::cout << xx.getName() << std::endl;
	return (0);
}
