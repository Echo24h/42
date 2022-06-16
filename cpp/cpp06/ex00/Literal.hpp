#ifndef _Literal_hpp_
#define _Literal_hpp_

#include <iostream>
#include <sstream>

enum literalType {
	INVALID_T,
	FLOAT_T,
	INT_T,
	DOUBLE_T,
	CHAR_T
};

class Literal {
	public:
		Literal(void);
		Literal(std::string val);
		Literal(Literal const & src);
		~Literal(void);
		Literal & operator=(Literal const & src);
	
		int	getInt() const;
		double getDouble() const;
		char getChar() const;
		float getFloat() const;
		void showValues(void) const;

	private:
		std::string 		_literalVal;
		std::stringstream	ss;
		int					_type;
		void		*_val;

		int getType(void) const;
		/*
		int			_intVal;
		float		_floatVal;
		double		_doubleVal;
		char		_charVal;
		*/
};

#endif
