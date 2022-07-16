#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(int ac, char *av[]) {
	try {
		PresidentialPardonForm	xx("targot");
		Bureaucrat				me("yo", 3);
		Bureaucrat				bigShit("bigShit", 150);

		xx.execute(me);
		me.executeForm(xx);
		bigShit.signForm(xx);
		xx.beSigned(bigShit);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
