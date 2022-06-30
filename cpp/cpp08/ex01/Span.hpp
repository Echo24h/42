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

		unsigned int 	getSize(void) const;
		void			addNumber(int nbr);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
	
	private:
		unsigned int	 	_sizeMax;
		std::vector<int>	_vec;

		Span(void);
};

#endif
