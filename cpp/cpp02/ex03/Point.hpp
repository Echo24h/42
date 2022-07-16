#ifndef _Point_hpp_
#define _Point_hpp_

#include <iostream>
#include "Fixed.hpp"

class Point {
	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const & src);
		~Point(void);

		Point & operator=(Point const & rhs);
	
		Fixed const &	getX(void) const;
		Fixed const &	getY(void) const;

	private:
		Fixed const	_x;
		Fixed const	_y;
};

std::ostream & operator<<(std::ostream &ostrm, Point const & src);

#endif
