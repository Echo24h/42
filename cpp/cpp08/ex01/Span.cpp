#include <iostream>
#include <algorithm>
#include <cmath>
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
	this->_sizeMax = rhs.getSizeMax();
	this->_vec = rhs._vec;
	return (*this);
}

static void print(int x) {
	std::cout << x << "\n";
}

std::ostream & operator<<(std::ostream & ostrm, Span const & rhs) {
	std::vector<int> vec = rhs.getVec();
	ostrm << "-\n";
	std::for_each(vec.begin(), vec.end(), &print);
	ostrm << "-\n";
	return (ostrm);
}

// --- public member functions --- 

unsigned int Span::getSizeMax(void) const {
	return (this->_sizeMax);
}

std::vector<int> Span::getVec(void) const {
	return (this->_vec);
}

void Span::addNumber(int nbr) {
	if (this->_vec.size() == this->_sizeMax) {
		throw (std::runtime_error("addNumber: Span maximum capacity reached, can't store more number"));
	}

	this->_vec.push_back(nbr);
}

void Span::addRandomNumbers(unsigned int n, int min, int max) {
	if (this->_sizeMax - this->_vec.size() < n) {
		throw (std::runtime_error("addNumbers: Span maximum capacity reached, can't store more number"));
	}
	srand(time(NULL));
	for (unsigned int i = 0; i < n; i++) {
		this->addNumber(min + (rand() % abs(max - min + 1)));
	}
}

unsigned int	Span::shortestSpan(void) {
	if (this->_vec.size() < 2) {
		throw (std::runtime_error("shortestSpan: invalid operation, Span contains less than 2 numbers"));
	}

	std::vector<int> tmpVec(this->_vec);
	std::sort(tmpVec.begin(), tmpVec.end());
	int shortest = std::abs(tmpVec.front() - tmpVec.back());

	iterator ite = tmpVec.end();
	for (iterator it = tmpVec.begin(); it != ite - 1; it++) {
		if (std::abs(*(it + 1) - *it) < shortest) {
			shortest = std::abs(*(it + 1) - *it);
		}
	}
	return (shortest);
}

unsigned int	Span::longestSpan(void) {
	if (this->_vec.size() < 2) {
		throw (std::runtime_error("longestSpan: invalid operation, Span contains less than 2 numbers"));
	}

	iterator itMin = std::min_element(this->_vec.begin(), this->_vec.end());
	iterator itMax = std::max_element(this->_vec.begin(), this->_vec.end());
	return (std::abs(*itMax - *itMin));
}
