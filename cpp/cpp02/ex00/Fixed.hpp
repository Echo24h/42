#ifndef _Fixed_hpp_
#define _Fixed_hpp_

#include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		~Fixed(void);
		Fixed &	operator=(Fixed const & src);
	
	public:
		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int					_bits;
		static int const	_nbBitsFrac;
};

#endif
