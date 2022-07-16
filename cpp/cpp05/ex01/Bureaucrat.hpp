#ifndef _Bureaucrat_hpp_
#define _Bureaucrat_hpp_

#include <iostream>

class Form;

class Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(std::string const name, int const grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat(void);
		Bureaucrat &	operator=(Bureaucrat const & src);
	
	public:
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrGrade(void);
		void		decrGrade(void);
		void		signForm(Form & src) const;

	public:
		class GradeTooLowException: public std::exception {
			public:
				const char * what() const throw() { return ("grade is too low"); };
		};

		class GradeTooHighException: public std::exception {
			public:
				const char * what() const throw() { return ("grade is too high"); };
		};

	private:
		std::string const	name;
		int					grade;
};

std::ostream &	operator<<(std::ostream & ostrm, Bureaucrat const & ros);

#endif
