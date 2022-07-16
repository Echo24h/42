#ifndef _ShrubberyCreationForm_hpp_
#define _ShrubberyCreationForm_hpp_

#include <iostream>
#include "Form.hpp"

class Bureaucrat;

class ShrubberyCreationForm: public Form {
	public:
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & src);
	
	public:
		void	execute(Bureaucrat const & executor) const;

	private:
		std::string	target;

	private:
		ShrubberyCreationForm(void);
};

#endif
