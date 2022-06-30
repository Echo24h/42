#ifndef _Literal_hpp_
#define _Literal_hpp_

#include <iostream>

class Literal {
	public:
		Literal(void);
		Literal(Literal const & src);
		~Literal(void);
		Literal &	operator=(Literal const & src);
	
	private:
		float	fVal;
		int		iVal;
		double	dVal;
		char	cVal;
};

#endif
