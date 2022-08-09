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

			// ---- constructor(s) ----
			explicit vector(allocator_type const & alloc = allocator_type()) {
				std::cout << "vector constructor | vector(allocator_type const & alloc) |" << std::endl;

				this->_alloc = alloc;
				this->_data = nullptr;
				this->_size = 0;
				this->_capacity = 0;
			}

			// think about n = 0 or n > alloc.max_size()
			// throw
			explicit vector(size_type n, value_type const & val = value_type(), allocator_type const & alloc = allocator_type()) {
				std::cout << "vector constructor | vector(size_type n, value_type const & val, allocator_type const & alloc) |" << std::endl;

				this->_alloc = alloc;
				this->_data = this->_alloc.allocate(n);
				this->_construct_at_end(n, val);
				this->_size = n;
				this->_capacity = n;
			}

			// TO DO
			template <typename InputIterator>
			vector(typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type & alloc = allocator_type()) {
				std::cout << "vector constructor | vector(InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type()) |" << std::endl;

				this->_alloc = alloc;
			}
			
			// trow
			vector(vector const & src) {
				std::cout << "vector constructor | vector(vector const & src) |" << std::endl;

				this->_alloc = src._alloc;
				this->_data = this->_alloc.allocate(src._capacity);
				for (int i = 0; i < src._size; i++) {
					this->_alloc.construct(this->_data + i, src._data[i]);
				}
				this->_size = src._size;
				this->_capacity = src._capacity;
			}

			// ---- destructor ----
			~vector(void) {
				std::cout << "vector destructor" << std::endl;

				this->clear();
				this->_alloc.deallocate(this->_data, this->_capacity);
			}

			// ---- operator(s) ----
			// throw
			vector & operator=(vector const & rhs) {
				this->clear();
				this->_alloc.deallocate(this->_data, this->_capacity);
				
				this->_data = this->_alloc.allocate(rhs._capacity);
				for (int i = 0; i < rhs._size; i++) {
					this->_alloc.construct(this->_data + i, rhs._data[i]);
				}
				this->_size = rhs._size;
				this->_capacity = rhs._capacity;

				return (*this);
			}

			reference operator[](size_type n) {
				return (this->_data + n);
			}

			const_reference operator[](size_type n) const {
				return (this->_data + n);
			}

			// ---- member function(s) ----
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
				return ((this->_size == 0) ? true : false);
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

			// TO DO
			template <class InputIterator>
  			void assign(InputIterator first, InputIterator last) {
				
			}

			// TO DO
			void assign(size_type n, const value_type& val) {
				
			}

			// trow
			void push_back(const value_type & val) {
				if (this->_size == this->_capacity) {
					this->_realloc((this->_size > 8) ? this->_size + this->_size / 2 : 4);
				}
				this->_construct_at_end(1, val);
			}

			void pop_back(void) {
				if (this->_size != 0) {
					this->_destroy_at_end(1);
				}
			}

			// TO DO
			iterator insert(iterator position, const value_type& val) {
				return (iterator());
			}

			// TO DO
			void insert(iterator position, size_type n, const value_type& val) {
				
			}

			// TO DO
			template <class InputIterator>
    		void insert(iterator position, InputIterator first, InputIterator last) {

			}

			// TO DO
			iterator erase(iterator position) {
				return (iterator());
			}

			// TO DO
			iterator erase(iterator first, iterator last) {
				return (iterator());
			}

			// TO DO
			void swap(vector & x) {
				swap(*this, x);
			}

			void clear(void) {
				this->_destroy_at_end(this->_size);
			}

			allocator_type get_allocator(void) const {
				return (this->_alloc);
			}

			// TODO
			// reverse_iterator rbegin(void);
			// const_reverse_iterator rbegin(void) const;
			// reverse_iterator rend(void);
			// const_reverse_iterator rend(void) const;

			// throw
			void resize(size_type n, value_type val = value_type()) {
				if (n == this->_size) {
					return ;
				} else if (n < this->_size) {
					this->_destroy_at_end(this->_size - n);
				} else {
					if (n > this->capacity) {
						this->_realloc(n);
					}
					this->_construct_at_end(n - this->_size, val);
				}
			}
			
			// trow
			void reserve(size_type n) {
				if (n <= this->capacity) {
					return ;
				} else if (n > this->max_size()) {
					throw (std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size"));
				} else {
					this->_realloc(n);
				}
			}

			// ---- friend(s) ----
			template <typename _T, typename _Allocator>
			friend std::ostream & operator<<(std::ostream &, vector<_T, _Allocator> const &);

			template <typename _T, typename _Allocator>
			friend void swap(vector<_T, _Allocator> & x, vector<_T, _Allocator> & y);

		private:
			pointer 		_data;
			size_type		_size;
			allocator_type	_alloc;
			size_type		_capacity;

			// not safe
			void _construct_at_end(size_type n, const_reference val) {
				std::cout << "in _construct_at_end\n";

				pointer ptr = this->end();
				for (int i = 0; i < n; i++) {
					this->_alloc.construct(ptr + i, val);
				}
				this->_size += n;
			}

			// not safe
			void _destroy_at_end(size_type n) {
				std::cout << "in _destroy_at_end\n";

				pointer ptr = this->end() - n;
				pointer end = this->end();
				for (; ptr != end; ptr++) {
					this->_alloc.destroy(ptr);
				}
				this->_size -= n;
			}

			// throw
			void _realloc(size_type newCapacity) {
				std::cout << "in _realloc\n";

				size_type newSize = (this->_size < newCapacity) ? this->_size : newCapacity;

				pointer newData = this->_alloc.allocate(newCapacity);
				for (int i = 0; i < newSize; i++) {
					newData[i] = this->_data[i];
				}

				this->clear();
				this->_alloc.deallocate(this->_data, this->_capacity);

				this->_data = newData;
				this->_size = newSize;
				this->_capacity = newCapacity;
			}
	};

	// ---- non-member function(s) ----
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
		std::cout << "data: ";
		for (int i = 0; i < rhs._size; i++) {
			std::cout << *(rhs._data + i) << " ";
		}
		std::cout << std::endl;
		return (ostrm);
	}
}

#endif