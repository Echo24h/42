#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(Point const & src) : _x(src.getX()), _y(src.getY()) {}

Point::~Point(void) {}

Point & Point::operator=(Point const & rhs) {
	(void)rhs;
	return (*this);
}

std::ostream & operator<<(std::ostream & ostrm, Point const & src) {
	ostrm << "( " << src.getX() << " ; " << src.getY() << " )";
	return (ostrm);
}

Fixed const &	Point::getX(void) const {
	return (this->_x);
}

Fixed const &	Point::getY(void) const {
	return (this->_y);
}

