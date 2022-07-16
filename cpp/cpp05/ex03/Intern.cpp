#include <iostream>
#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

std::string	const	Intern::formsName[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

Intern::Intern(void) {}

Intern::~Intern(void) {}

Form *	Intern::makeForm(std::string const formName, std::string const target) const {
	int	i = 0;
	while (i < 3) {
		if (!formName.compare(this->formsName[i])) {
			break ;
		}
		i++;
	}
	switch (i) {
		case 0:
			std::cout << "Intern creates shrubbery creation form\n";
			return (new ShrubberyCreationForm(target));
		case 1:
			std::cout << "Intern creates shrubbery creation form\n";
			return (new ShrubberyCreationForm(target));
		case 2:
			std::cout << "Intern creates shrubbery creation form\n";
			return (new ShrubberyCreationForm(target));
		default:
			std::cout << "Intern tried to create an invalid " << formName << " form\n";
			break;
	}
	return (nullptr);
}
