#ifndef _vector_hpp_
#define _vector_hpp_

#include <iostream>

namespace ft {

	template <class T, class Allocator = std::allocator<T> >
	class vector {
		public:
			typedef Allocator									allocator_type;
			typedef typename allocator_type::value_type			value_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::size_type			size_type;
			typedef	typename allocator_type::difference_type	difference_type;
			typedef	pointer										iterator;
			typedef	const_pointer								const_iterator;
			// typedef											reverse_iterator
			// typedef											const_reverse_iterator

		public:
			// constructor(s)
			vector(void);
			vector(vector const & src);

			// destructor
			~vector(void);

			// operator(s)
			vector & operator=(vector const & rhs);

			// member function(s)
		
		private:
			T *	_array;
	};

	template <class T, class Allocator>
	vector<T, Allocator>::vector(void) {
		this->_array = nullptr;
	}
}



#endif
