#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "Form.hpp"
#include "time.h"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) :
	Form("Robotomy", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) :
	Form("Robotomy", 72, 45),
	target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) :
	Form(src.getName(), src.getGradeReqToSign(), src.getGradeReqToExec()),
	target(src.target) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & src) {
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getGradeReqToExec()) {
		throw (std::runtime_error("ShrubberyCreationForm::GradeTooLowException"));
	} else {
		drawTree(this->target + "_shrubbery", 10, '*');
	}
}
