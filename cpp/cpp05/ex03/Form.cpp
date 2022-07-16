#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form(void) : 
	name("Default"),
	isSigned(false),
	gradeReqToSign(150),
	gradeReqToExec(150) {}

Form::Form(std::string const name, int const gradeReqToSign, int const gradeReqToExec) :
	name(name),
	isSigned(false),
	gradeReqToSign(gradeReqToSign),
	gradeReqToExec(gradeReqToExec) {
	if (gradeReqToSign < 1 || gradeReqToExec < 1) {
		throw (Form::GradeTooHighException());
	} else if (gradeReqToSign > 150 || gradeReqToExec > 150) {
		throw (Form::GradeTooLowException());
	}
}

Form::Form(Form const & src) :
	name(src.name),
	isSigned(false),
	gradeReqToSign(src.gradeReqToSign),
	gradeReqToExec(src.gradeReqToExec) {}

Form::~Form(void) {}

Form &	Form::operator=(Form const & src) {
	return (*this);
}

std::ostream &	operator<<(std::ostream & ostrm, Form const & ros) {
	ostrm << "Form: name=" << ros.getName() << " | isSigned=" << ros.getIsSigned() << " | gradeReqToSign=" << ros.getGradeReqToSign() << " | gradeReqToExec=" << ros.getGradeReqToExec();
	return (ostrm);
 }

// --- member functions ---

std::string	Form::getName(void) const {
	return (this->name);
}

bool	Form::getIsSigned(void) const {
	return (this->isSigned);
}

int		Form::getGradeReqToSign(void) const {
	return (this->gradeReqToSign);
}

int		Form::getGradeReqToExec(void) const {
	return (this->gradeReqToExec);
}

void	Form::beSigned(Bureaucrat const & src) {
	if (src.getGrade() > this->gradeReqToSign) {
		throw (Form::GradeTooLowException());
	} else {
		this->isSigned = true;
		std::cout << src.getName() << " signed form " << this->name << std::endl;
	}
}
