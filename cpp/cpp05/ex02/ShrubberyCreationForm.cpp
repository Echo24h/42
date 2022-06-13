#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include "Form.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("shrubbery", 145, 137) {
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src) {
	return (*this);
}
