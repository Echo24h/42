#ifndef _vector_hpp_
#define _vector_hpp_

#include <iostream>
#include <exception>
#include <algorithm>
#include "type_traits.hpp"
#include "iterator.hpp"

/*
	should i start by implementing iterators to use them in my functions to search through vector?
*/

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
			typedef const_pointer								const_iterator;
			// typedef											reverse_iterator
			// typedef											const_reverse_iterator

			// constructor(s)
			explicit vector(allocator_type const & alloc = allocator_type()) {
				std::cout << "vector constructor | vector(allocator_type const & alloc) |" << std::endl;
				this->_alloc = alloc;
				this->_data = nullptr;
				this->_size = 0;
				this->_capacity = 0;
			}

			// think about n = 0 or n > alloc.max_size()
			explicit vector(size_type n, value_type const & val = value_type(), allocator_type const & alloc = allocator_type()) {
				std::cout << "vector constructor | vector(size_type n, value_type const & val, allocator_type const & alloc) |" << std::endl;
				this->_alloc = alloc;
				this->_size = n;
				this->_capacity = n;

				try {
					this->_data = this->_alloc.allocate(n);
				} catch (std::exception & e) {
					throw (e);
				}

				for (int i = 0; i < n; i++) {
					this->_alloc.construct(this->_data + i, val);
				}
			}

			// TODO
			
			template <typename InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type()) {
				std::cout << "vector constructor | vector(InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type()) |" << std::endl;
				this->_alloc = alloc;
			}
			
			
			// TODO
			vector(vector const & src) {
				std::cout << "vector constructor | vector(vector const & src) |" << std::endl;
				*this = src;
			}

			// destructor
			~vector(void) {
				std::cout << "vector destructor" << std::endl;
				for (int i = 0; i < this->_size; i++) {
					this->_alloc.destroy(this->_data + i);
				}
				this->_alloc.deallocate(this->_data, this->_size);
			}

			// operator(s)
			vector & operator=(vector const & rhs) {
				this->~vector();

				try {
					this->_data = this->_alloc.allocate(rhs._size);
				} catch (std::exception & e) {
					throw (e);
				}

				this->_alloc = rhs._alloc;
				this->_size = rhs._size;
				for (int i = 0; i < rhs._size; i++) {
					this->_alloc.construct(this->_data + i, *(rhs._data + i));
				}

				return (*this);
			}

			reference operator[](size_type n) {
				return (this->_data + n);
			}

			const_reference operator[](size_type n) const {
				return (this->_data + n);
			}

			// member function(s)
			iterator begin(void) {
				return (this->_data);
			}

			const_iterator begin(void) const {
				return (this->_data);
			}

			iterator end(void) {
				return (this->_data + this->_size);
			}

			const_iterator end(void) const {
				return (this->_data + this->_size);
			}

			size_type size(void) const {
				return (this->_size);
			}

			size_type max_size(void) const {
				return (this->_alloc.max_size());
			}

			size_type capacity(void) const {
				return (this->_capacity);
			}

			bool empty(void) const {
				return (this->_size == 0 ? true : false);
			}

			reference at(size_type n) {
				if (n >= this->_size) {
					throw std::out_of_range("vector");
				} else {
					return (this->_data + n);
				}
			}

			const_reference at(size_type n) const {
				if (n >= this->_size) {
					throw std::out_of_range("vector");
				} else {
					return (this->_data + n);
				}
			}

			reference front(void) {
				return (this->_data);
			}

			const_reference front(void) const {
				return (this->_data);
			}

			reference back(void) {
				return (this->_data + this->_size - 1);
			}

			const_reference back(void) const {
				return (this->_data + this->_size - 1);
			}

			template <class InputIterator>
  			void assign(InputIterator first, InputIterator last) {
				
			}

			void assign(size_type n, const value_type& val) {
				
			}

			void push_back(const value_type & val) {
				if (this->_size == this->_capacity) {
					try {
						//this->resize(this->capacity + this->capacity / 2)
					} catch (std::exception & e) {
						throw (e);
					}
				}

				this->_data[this->size] = val;
				this->size++;	
			}

			void pop_back(void) {
				if (this->size != 0) {
					//this->_alloc.destroy(this->_data + this->_size)	
				}
			}

			iterator insert(iterator position, const value_type& val) {
				return (iterator());
			}

			void insert(iterator position, size_type n, const value_type& val) {
				
			} 

			template <class InputIterator>
    		void insert(iterator position, InputIterator first, InputIterator last) {

			}

			iterator erase(iterator position) {
				return (iterator());
			}

			iterator erase(iterator first, iterator last) {
				return (iterator());
			}

			void swap(vector & x) {
				swap(*this, x);
			}

			void clear(void) {
				for (int i = 0; i < this->_size; i++) {
					this->_alloc.destroy(this->_data + i);
				}
				this->_size = 0;
			}

			allocator_type get_allocator(void) const {
				return (this->_alloc);
			}

			// TODO
			//reverse_iterator rbegin(void);
			//const_reverse_iterator rbegin(void) const;
			//reverse_iterator rend(void);
			//const_reverse_iterator rend(void) const;

			// use insert / erase
			void resize(size_type n, value_type val = value_type()) {
				if (n < this->_size) {

				} else if (n > this->_size) {
					if (n > this->_capacity) {

					}
				}
			}
			
			/*
				need explicit throw msg
			*/
			void reserve(size_type n) {
				if (n > this->max_size() - this->_size) {
					throw (std::length_error(""));
				} else if (n <= this->capacity) {
					return ;
				}

				ft::vector<value_type, allocator_type> tmp(n);
				//ft::swap(*this, tmp);
				*this = tmp;
			}

			// friend(s)
			template <typename _T, typename _Allocator>
			friend std::ostream & operator<<(std::ostream &, vector<_T, _Allocator> const &);

			template <typename _T, typename _Allocator>
			friend void swap(vector<_T, _Allocator> & x, vector<_T, _Allocator> & y);

		private:
			pointer 		_data;
			size_type		_size;
			allocator_type	_alloc;
			size_type		_capacity;
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

	/*
		should i use assert()?
		should i swap pointers only?
	*/
	template <typename T, typename Allocator>
	void swap(vector<T, Allocator> & x, vector<T, Allocator> & y) {
		std::swap(x._data, y._data);
		std::swap(x._size, y._size);
		std::swap(x._capacity, y._capacity);
		std::swap(x._alloc, y._alloc);
	}

	template <typename T, typename Allocator>
	std::ostream &	operator<<(std::ostream & ostrm, vector<T, Allocator> const & rhs) {
		std::cout << "size: " << rhs._size << std::endl;
		std::cout << "capacity: " << rhs._capacity << std::endl;
		std::cout << "begin: " << rhs._data << std::endl;
		//std::cout << "allocator: " << &*(rhs._alloc) << std::endl;
		std::cout << "tab: ";
		for (int i = 0; i < rhs._size; i++) {
			std::cout << *(rhs._data + i) << " ";
		}
		std::cout << std::endl;
		return (ostrm);
	}
}

#endif