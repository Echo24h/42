#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
	Form("Presidential", 25, 5),
	target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) :
	Form("Presidential", 25, 5),
	target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) :
	Form(src.getName(), src.getGradeReqToSign(), src.getGradeReqToExec()),
	target(src.target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const & src) {
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getGradeReqToExec()) {
		throw (std::runtime_error("RobotomyRequestForm::GradeTooLowException"));
	} else {
		std::cout << this->target << " was forgiven by Zaphod Beeblebrox\n";
	}
	return;
}