#ifndef _Bureaucrat_hpp_
#define _Bureaucrat_hpp_

#include <iostream>

class Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(std::string const name, int const grade) ;
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat(void);
		Bureaucrat &	operator=(Bureaucrat const & src);
	
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrGrade(void);
		void		decrGrade(void);

	private:
		std::string const	name;
		int					grade;
};

std::ostream &	operator<<(std::ostream & ostrm, Bureaucrat const & ros);

#endif
