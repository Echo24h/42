#include "Literal.hpp"
#include <iostream>

bool isFloat(std::string str);
bool isInt(std::string str);
bool isDouble(std::string str);
bool isChar(std::string str);

Literal::Literal(void) :
	_literalVal(""),
	_val(nullptr) {}

Literal::Literal(std::string literalVal) :
	_literalVal(literalVal) {
	switch (this->getType())
	{
		case INT_T:
			this->_val = new int;
			*(int *)this->_val = std::atoi(literalVal.data());
			break;
		case FLOAT_T:
			this->_val = new float;
			*(float *)this->_val = std::atof(literalVal.data());
			break;
		case DOUBLE_T:
			this->_val = new double;
			*(int *)this->_val = std::atoi(literalVal.data());
			break;
		case CHAR_T:
			this->_val = new char;
			*(char *)this->_val = this->_literalVal[0]; // implicit cast
			break;
		default:
			std::cerr << "Invalid Literal\n";
			break;
	}
}

Literal::Literal(Literal const & src) {
	*this = src;
}

Literal::~Literal(void) {
	switch (this->getType())
	{
		case INT_T:
			delete (int *)this->_val;
			break;
		case FLOAT_T:
			delete (float *)this->_val;
			break;
		case DOUBLE_T:
			delete (double *)this->_val;
			break;
		case CHAR_T:
			delete (char *)this->_val;
			break;
		default:
			break;
	}
}

Literal &	Literal::operator=(Literal const & src) {
	this->_val = src._val;
	return (*this);
}

int Literal::getType(void) const {
	if (this->_literalVal.empty()) {
		return (INVALID_T);
	} else if (isInt(this->_literalVal)) {
		return (INT_T);
	} else if (isFloat(this->_literalVal)) {
		return (FLOAT_T);
	} else if (isDouble(this->_literalVal)) {
		return (DOUBLE_T);
	} else if (isChar(this->_literalVal)) {
		return (CHAR_T);
	} else {
		return (INVALID_T);
	}
}

int	Literal::getInt() const {
	return (0);
}

double Literal::getDouble() const {
	return (0.0);
}

char Literal::getChar() const {
	return ('0');
}

float Literal::getFloat() const {
	return (0.0f);
}

// --- non-member functions ---

bool isFloat(std::string str) {
	if (str.length() < 2
		|| str.find_first_not_of("0123456789.f", 0) != std::string::npos
		|| str.find_first_of(".", 0) == std::string::npos
		|| str.find_first_of(".", 0) != str.find_last_of(".")
		|| str.back() != 'f') {
		return (false);
	} else {
		return (true);
	}
}

bool isInt(std::string str) {
	if (str.find_first_not_of("0123456789", 0) != std::string::npos) {
		return (false);
	} else {
		return (true);
	}
}

bool isDouble(std::string str) {
	if (str.length() < 2
		|| str.find_first_not_of("0123456789.", 0) != std::string::npos
		|| str.find_first_of(".", 0) == std::string::npos
		|| str.find_first_of(".", 0) != str.find_last_of(".")) {
		return (false);
	} else {
		return (true);
	}
}

bool isChar(std::string str) {
	return ((str.length() == 1) ? true : false);
}
