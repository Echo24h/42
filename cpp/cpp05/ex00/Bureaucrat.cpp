#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void) : 
	name("anonyme"),
	grade(150) {}

Bureaucrat::Bureaucrat(std::string const name, int const grade) :
	name(name),
	grade(grade) {
	if (grade > 150) {
		throw (std::invalid_argument("Bureaucrat::GradeTooLowException"));
	} else if (grade < 1) {
		throw (std::invalid_argument("Bureaucrat::GradeTooHighException"));
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) {
	*this = src;
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & src) {
	this->grade = src.grade;
	return (*this);
}

std::string	Bureaucrat::getName(void) const {
	return (this->name);
}

int	Bureaucrat::getGrade(void) const {
	return (this->grade);
}

void	Bureaucrat::incrGrade(void) {
	if (this->grade == 1) {
		throw (std::invalid_argument("Bureaucrat::GradeTooHighException"));
	} else {
		this->grade--;
	}
}

void	Bureaucrat::decrGrade(void) {
	if (this->grade == 150) {
		throw (std::invalid_argument("Bureaucrat::GradeTooLowException"));
	} else {
		this->grade++;
	}
}

std::ostream &	operator<<(std::ostream & ostrm, Bureaucrat const & ros) {
	ostrm << ros.getName() << ", bureaucrat grade " << ros.getGrade();
	return (ostrm);
}
