#ifndef _Form_hpp_
#define _Form_hpp_

#include <iostream>

class Bureaucrat;

class Form {
	public:
		Form(void);
		Form(std::string const name, int const gradeReqToSign, int const gradeReqToExec);
		Form(Form const & src);
		~Form(void);
		Form &	operator=(Form const & src);

	public:
		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		int				getGradeReqToSign(void) const;
		int				getGradeReqToExec(void) const;
		void			beSigned(Bureaucrat const & src);

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
		bool				isSigned;
		int const			gradeReqToSign;
		int const			gradeReqToExec;
};

std::ostream &	operator<<(std::ostream & ostrm, Form const & ros);

#endif
