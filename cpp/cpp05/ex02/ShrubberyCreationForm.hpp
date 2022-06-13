#ifndef _ShrubberyCreationForm_hpp_
#define _ShrubberyCreationForm_hpp_

#include <iostream>
#include "Form.hpp"

class ShrubberyCreationForm: public Form {
	public:
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & src);
	
	private:
		std::string	target;
};

#endif
