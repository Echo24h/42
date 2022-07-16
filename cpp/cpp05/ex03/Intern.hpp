#ifndef _Intern_hpp_
#define _Intern_hpp_

#include <iostream>
#include "Form.hpp"

class Intern {
	public:
		Intern(void);
		
		~Intern(void);

		Form *	makeForm(std::string const formName, std::string const target) const;
	
	private:
		static std::string const	formsName[3];

		Intern(Intern const & src);
		Intern & operator=(Intern const & src);
};

#endif
