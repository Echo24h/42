#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "Form.hpp"
#include "time.h"
#include "Bureaucrat.hpp"
#include <stdlib.h>
#include <time.h>

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
		throw (Form::GradeTooLowException());
	} else {
		srand(time(nullptr));
		if (rand() % 2) {
			std::cout << this->target << "has been robotomized" << std::endl;
		} else {
			std::cout << this->target << "could not been robotomized" << std::endl;
		}
	}
}
