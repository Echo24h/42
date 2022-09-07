#ifndef _Array_hpp_
#define _Array_hpp_

#include <iostream>

template<class T>
class Array {
	public:
		Array(void) {
			this->_array = new T();
			this->_size = 0;
		}

		Array(unsigned int n) {
			this->_array = new T[n]();
			this->_size = n;
		}

		Array(Array const & src) {
			this->_array = new T[src._size];
			this->_size = src._size;

			for (unsigned int i = 0; i < this->_size; i++) {
				this->_array[i] = src._array[i];
			}
		}

		~Array(void) {
			delete [] this->_array;
		}

		Array & operator=(Array const & rhs) {
			delete [] this->_array;
			this->_array = new T[rhs._size]();
			this->_size = rhs._size;

			for (unsigned int i = 0; i < this->_size; i++) {
				this->_array[i] = rhs._array[i];
			}
			return (*this);
		}

		T & operator[](unsigned int idx) const {
			if (idx >= this->_size) {
				throw (std::runtime_error("invalid access"));
			}
			return (this->_array[idx]);
		}

		unsigned int size(void) const {
			return (this->_size);
		}

	private:
		T * 			_array;
		unsigned int 	_size;
};

template<class T>
std::ostream &	operator<<(std::ostream & ostrm, Array<T> const & rhs) {
	ostrm << "| "; 
	for (unsigned int i = 0; i < rhs.size(); i++) {
		ostrm << rhs[i];
		if (i != rhs.size() - 1)
			ostrm << " ";
	}
	ostrm << " |";
	return (ostrm);
}

#endif
