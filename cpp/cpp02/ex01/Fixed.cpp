#include "Fixed.hpp"
#include <iostream>
#include <math.h>

int const	Fixed::_nbBitsFracPart = 8;

Fixed::Fixed(void) {
	std::cout << "Default constructor called\n";
	this->_bits = 0;
}

Fixed::Fixed(int const x) {
	std::cout << "Int constructor called\n";
	this->_bits = x << this->_nbBitsFracPart;
}

Fixed::Fixed(float const f) {
	std::cout << "Float constructor called\n";
	this->_bits = (int)roundf(f * (1 << this->_nbBitsFracPart));
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
	return (this->_bits);
}

void	Fixed::setRawBits(int const raw) {
	this->_bits = raw;
}

float 	Fixed::toFloat(void) const {
	return ((float)this->_bits / (1 << this->_nbBitsFracPart));
}

int 	Fixed::toInt(void) const {
	int	res;
	int	bits = this->_bits;
	int	intPart = bits >> this->_nbBitsFracPart;

	res = 0;
	for (int i = 0; i < 32 - this->_nbBitsFracPart; i++) {
		if ((intPart >> i & 1)) {
			res += (i == 32 - this->_nbBitsFracPart - 1) ? -(1 << i) : 1 << i;
		}
	}
	return (res);
}

void	Fixed::showRange(void) const {
	int	nbBitsIntPart = 32 - this->_nbBitsFracPart;
	int min = -(1 << (nbBitsIntPart - 1));
	int max = (1 << (nbBitsIntPart - 1)) - 1;
	std::cout << "Fixed Numbers range is [" << min << " ; " << max << "]\n";
}

std::ostream &	operator<<(std::ostream &ostrm, Fixed const & src) {
	ostrm << src.toFloat();
	return (ostrm);
}
