#include <iostream>
#include <algorithm>
#include "Span.hpp"

typedef std::vector<int>::iterator iterator;

// --- constructor(s) / destructor ---

Span::Span(void) {}

Span::Span(unsigned int sizeMax) {
	_sizeMax = sizeMax;
}

Span::Span(Span const & src) {
	*this = src;
}

Span::~Span(void) {}

// --- operator(s) ---

Span & Span::operator=(Span const & rhs) {
	this->_sizeMax = rhs.getSize();
	this->_vec = rhs._vec;
	return (*this);
}

// --- public member functions --- 

unsigned int Span::getSize(void) const {
	return (this->_sizeMax);
}

void Span::addNumber(int nbr) {
	if (this->_vec.size() == this->_sizeMax) {
		throw (std::runtime_error("addNumber: can't store anymore number"));
	}
	this->_vec.push_back(nbr);
}

unsigned int	Span::shortestSpan(void) {


}

unsigned int	Span::longestSpan(void) {
	iterator itMin = std::min_element(this->_vec.begin(), this->_vec.end());
	iterator itMax = std::max_element(this->_vec.begin(), this->_vec.end());
	return (*itMax - *itMin);
}
