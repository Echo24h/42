#ifndef _Array_hpp_
#define _Array_hpp_

#include <iostream>

template<class T>
class Array {
	public:
		Array(void);
		Array(unsigned int n);
		Array(Array<T> const & src);
		~Array(void);
		Array<T> & operator=(Array<T> const & rhs);
		T & operator[](unsigned int size);

		unsigned int size(void) const;
	private:
		T * array;
		unsigned int sizeArray;

};

template<class T>
std::ostream &	operator<<(std::ostream & ostrm, Array<T> const & rhs);

#endif
