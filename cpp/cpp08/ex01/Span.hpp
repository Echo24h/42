#ifndef _Span_hpp_
#define _Span_hpp_

#include <iostream>
#include <vector>

class Span {
	public:
		Span(unsigned int sizeMax);
		Span(Span const & src);
		~Span(void);
		Span & operator=(Span const & rhs);

		unsigned int		getSizeMax(void) const;
		std::vector<int>	getVec(void) const;
		void				addNumber(int nbr);
		void				addRandomNumbers(unsigned int n, int min, int max);		
		unsigned int		shortestSpan(void);
		unsigned int		longestSpan(void);
	
	private:
		unsigned int	 	_sizeMax;
		std::vector<int>	_vec;

		Span(void);
};

std::ostream & operator<<(std::ostream & ostrm, Span const & rhs);

#endif
