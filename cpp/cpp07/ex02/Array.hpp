#ifndef _Array_hpp_
#define _Array_hpp_

#include <iostream>

template<class T>
class Array {
	public:
		Array<T>(void) {
			this->array = new T;
			this->sizeArray = 0;
		}

		Array<T>(unsigned int n) {
			this->array = new T[n];
			this->sizeArray = n;
		}

		Array<T>(Array<T> const & src) {
			*this = src;
		}

		~Array<T>(void) {
			delete [] this->array;
		}

		Array<T> & operator=(Array<T> const & rhs) {
			for (unsigned int i = 0; i < rhs.size(); i++) {
				this->array[i] = rhs.array[i];
			}
			this->sizeArray = rhs.sizeArray;
			return (*this);
		}

		T & operator[](unsigned int idx) const {
			if (idx >= this->sizeArray) {
				throw (std::runtime_error("invalid access"));
			}
			return (this->array[idx]);
		}

		unsigned int size(void) const {
			return (this->sizeArray);
		}

	private:
		T * array;
		unsigned int sizeArray;

};

template<class T>
std::ostream &	operator<<(std::ostream & ostrm, Array<T> const & rhs) {
	ostrm << "|"; 
	for (unsigned int i = 0; i < rhs.size(); i++) {
		ostrm << rhs[i];
		if (i != rhs.size() - 1)
			ostrm << "|";
	}
	ostrm << "|";
	return (ostrm);
}

#endif