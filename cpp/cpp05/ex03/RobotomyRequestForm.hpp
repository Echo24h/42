#ifndef _RobotomyRequestForm_hpp_
#define _RobotomyRequestForm_hpp_

#include <iostream>
#include "Form.hpp"

class Bureaucrat;

class RobotomyRequestForm: public Form {
	public:
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		~RobotomyRequestForm(void);
		RobotomyRequestForm & operator=(RobotomyRequestForm const & src);

	public:
		void	execute(Bureaucrat const & executor) const;
	
	private:
		std::string	target;

	private:
		RobotomyRequestForm(void);
};

#endif
