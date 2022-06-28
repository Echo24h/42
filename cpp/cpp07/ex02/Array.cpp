#include "Array.hpp"
#include <iostream>

template<class T>
Array<T>::Array(void) {
	this->array = new T;
	this->sizeArray = 0;
}

template<class T>
Array<T>::Array(unsigned int n) {
	this->array = new T[n];
	this->sizeArray = n;
}

template<class T>
Array<T>::Array(Array<T> const & src) {
	*this = src;
}

template<class T>
Array<T>::~Array(void) {
	delete this->array;
}

template<class T>
Array<T> & Array<T>::operator=(Array<T> const & rhs) {
	for (int i = 0; i < rhs.sizeArray; i++) {
		this->array[i] = rhs.array[i];
	}
	this->sizeArray = rhs.sizeArray;
	return (*this);
}

template<class T>
T & Array<T>::operator[](unsigned int idx) {
	if (idx >= this->sizeArray) {
		throw (std::runtime_error("invalid access"));
	}
	return (this->array[idx]);
}

template<class T>
std::ostream &	operator<<(std::ostream & ostrm, Array<T> const & rhs) {
	ostrm << "|"; 
	for (int i = 0; i < rhs.sizeArray; i++) {
		ostrm << rhs[i] << "|"; 
	}
	ostrm << "|";
}

template<class T>
unsigned int Array<T>::size(void) const {
	return (this->sizeArray);
}
