#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include "Form.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form() {
	
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) {

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src) {
	return (*this);
}
