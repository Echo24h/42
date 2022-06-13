#ifndef _Intern_hpp_
#define _Intern_hpp_

#include <iostream>
#include "Form.hpp"

class Intern {
	public:
		Intern(void);
		Intern(Intern const & src);
		~Intern(void);
		Intern & operator=(Intern const & src);
		
		Form *	makeForm(std::string const formName, std::string const target) const;
	
	private:
		static std::string const	formsName[3];
};

#endif
