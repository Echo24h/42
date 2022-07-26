#ifndef _vector_hpp_
#define _vector_hpp_

#include <iostream>

namespace ft {
	template <typename T, typename Allocator = std::allocator<T> >
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

			// constructor(s)
			explicit vector(allocator_type const & alloc = allocator_type()) {
				std::cout << "vector constructor | vector(allocator_type const & alloc) |" << std::endl;
				this->_alloc = alloc;
				this->_ptr = nullptr;
				this->_size = 0;
			}

			// think about n = 0 or n > alloc.max_size()
			explicit vector(size_type n, value_type const & val = value_type(), allocator_type const & alloc = allocator_type()) {
				std::cout << "vector constructor | vector(size_type n, value_type const & val, allocator_type const & alloc) |" << std::endl;
				this->_alloc = alloc;
				this->_size = n;
				this->_alloc.allocate(n, this->_begin);
				for (int i = 0; i < n; i++) {
					this->_alloc.construct(this->_begin + i, val);
				}
			}

			// TODO
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type()) {
				std::cout << "vector constructor | vector(InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type()) |" << std::endl;
				this->_alloc = alloc;
			}
			
			// TODO
			vector(vector const & src) {
				std::cout << "vector constructor | vector(vector const & src) |" << std::endl;
				this->_alloc = src._alloc;
				this->~vector();
				this->_alloc.allocate(src._size, this->_begin);
				for (int i = 0; i < src._size; i++) {
					this->_alloc.construct(this->_begin + i, *(src._begin + i));
				}
				this->_size = src._size;
			}

			// destructor
			~vector(void) {
				std::cout << "vector destructor" << std::endl;
				for (int i = 0; i < this->_size; i++) {
					this->_alloc.destroy(this->_begin + i);
				}
				this->_alloc.deallocate(this->_begin, this->_size);
			}

			// operator(s)
			vector & operator=(vector const & rhs);

			// member function(s)
			pointer getPtr(void) {
				return (this->_begin);
			}

			iterator begin(void) {
				return (this->_begin);
			}

			const_iterator begin(void) const {
				return (this->_begin);
			}

			iterator end(void) {
				return (this->_begin + this->_size);
			}

			const_iterator end(void) const {
				return (this->_begin + this->_size);
			}

			friend std::ostream &	operator<<(std::ostream & ostrm, vector<T, Allocator> const & rhs);
 
		private:
			pointer 		_begin;
			size_type		_size;
			allocator_type	_alloc;
	};

	// non-member function(s)
	template <typename T, typename Allocator>
	bool operator==(vector<T, Allocator> const & lhs, vector<T, Allocator> const & rhs);

	template <typename T, typename Allocator>
	bool operator<(vector<T, Allocator> const & lhs, vector<T, Allocator> const & rhs);

	template <typename T, typename Allocator>
	bool operator<=(vector<T, Allocator> const & lhs, vector<T, Allocator> const & rhs);

	template <typename T, typename Allocator>
	bool operator>(vector<T, Allocator> const & lhs, vector<T, Allocator> const & rhs);

	template <typename T, typename Allocator>
	bool operator>=(vector<T, Allocator> const & lhs, vector<T, Allocator> const & rhs);

	template <typename T, typename Allocator>
	void swap(vector<T, Allocator> & x, vector<T, Allocator> & y);
}

template <typename T, typename Allocator>
std::ostream &	operator<<(std::ostream & ostrm, vector<T, Allocator> const & rhs) {
	for (int i = 0; i < rhs._size; i++) {
		std::cout << *(rhs._begin + i);
	}
}

#endif
