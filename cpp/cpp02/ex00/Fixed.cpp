#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) {
	std::cout << "Default constructor called\n";
	this->_bits = 0;
}

Fixed::Fixed(Fixed const & src) {
	std::cout << "Copy constructor called\n";
	*this = src;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called\n";
}

Fixed &	Fixed::operator=(Fixed const & src) {
	std::cout << "Copy assignment operator called\n";
	this->_bits = src._bits;
	return (*this);
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (this->_bits);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	this->_bits = raw;
}
