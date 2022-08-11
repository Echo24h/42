#ifndef _vector_hpp_
#define _vector_hpp_

#include <iostream>
#include <exception>
#include <algorithm>
#include "type_traits.hpp"
#include "iterator.hpp"

namespace ft
{
	salut
	template <typename T, typename Allocator = std::allocator<T> >
	class vector
	{
		public:
			// ---- member type(s) ----
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
			typedef	ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

			// ---- constructor(s) ----
			explicit vector(allocator_type const & alloc = allocator_type())
				: _alloc(alloc), _data(nullptr), _capacity(0), _size(0)
			{}

			explicit vector(size_type n, value_type const & val = value_type(), allocator_type const & alloc = allocator_type())
				: vector(alloc)
			{
				this->_data = this->_alloc.allocate(n);
				this->_capacity = n;
				this->_construct_at_end(n, val);
			}

			template <typename InputIterator>
			vector(typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first,
				InputIterator last,
				const allocator_type & alloc = allocator_type())
				: vector(alloc)
			{
				size_type n = last - first;
				this->_alloc.allocate(this->_data, n);
				this->_capacity = n;
				this->_construct_at_end(first, last);
			}
			
			vector(vector const & src)
				: vector()
			{
				this->_data = this->_alloc.allocate(src._capacity);
				this->_capacity = src._capacity;
				this->_construct_at_end(src.begin(), src.end());
			}

			// ---- destructor ----
			~vector(void)
			{
				this->clear();
				this->_alloc.deallocate(this->_data, this->_capacity);
				this->_capacity = 0;
			}

			// ---- operator(s) ----
			vector &
			operator=(vector const & rhs)
			{
				this->clear();
				if (this->_capacity < rhs._size)
					this->_realloc(rhs._capacity);
				this->_construct_at_end(rhs.begin(), rhs.end());
				return *this;
			}

			reference 		operator[](size_type n) 		{ return this->_data + n; }
			const_reference operator[](size_type n) const 	{ return this->_data + n; }

			// ---- member function(s) ----
			iterator 		begin(void) 		{ return this->_data; }
			const_iterator 	begin(void) const 	{ return this->_data; };
			iterator 		end(void) 			{ return this->_data + this->_size; }
			const_iterator 	end(void) const 	{ return this->_data + this->_size; };

			reverse_iterator 		rbegin(void) 		{ return reverse_iterator(this->end()); }
			const_reverse_iterator 	rbegin(void) const	{ return const_reverse_iterator(this->end()); };
			reverse_iterator 		rend(void) 			{ return reverse_iterator(this->begin()); }
			const_reverse_iterator 	rend(void) const 	{ return const_reverse_iterator(this->begin()); }

			size_type 		size(void) const 			{ return this->_size; }
			size_type 		max_size(void) const 		{ return this->_alloc.max_size(); }
			size_type 		capacity(void) const 		{ return this->_capacity; }
			allocator_type 	get_allocator(void) const 	{ return this->_alloc; }

			reference 		front(void) 		{ return this->_data; }
			const_reference	front(void) const 	{ return this->_data; }
			reference 		back(void) 			{ return this->_data + this->_size - 1; }
			const_reference back(void) const 	{ return this->_data + this->_size - 1; }

			void	clear(void)			{ this->_destroy_at_end(this->_size); }
			bool	empty(void) const	{ return (this->_size == 0 ? true : false); }

			reference
			at(size_type n)
			{
				if (n >= this->_size)
					throw std::out_of_range("vector");
				else
					return this->_data + n;
			}

			const_reference
			at(size_type n) const
			{
				if (n >= this->_size)
					throw std::out_of_range("vector");
				else
					return this->_data + n;
			}

			template <class InputIterator>
			void
			assign(InputIterator first, InputIterator last)
			{
				this->clear();
				size_type newSize = last - first;
				if (newSize > this->_capacity)
					this->_realloc(newSize);
				this->_construct_at_end(first, last);
			}

			void
			assign(size_type n, const value_type& val)
			{
				this->clear();
                if (n > this->_capacity)
                    this->_realloc(n);
                this->_construct_at_end(n, val);	
			}

			void
			push_back(const value_type & val)
			{
				if (this->_size == this->_capacity)
					this->_grow();
				this->_construct_at_end(1, val);
			}

			void
			pop_back(void)
			{
				if (this->_size != 0)
					this->_destroy_at_end(1);
			}

			iterator
			insert(iterator position, const value_type & val)
			{
				if (this->_size + 1 > this->_capacity)
					this->_grow();
				reverse_iterator rend(position);
				reverse_iterator rit(this->rbegin());
				for (; rit != rend; rit++)
					*(rit + 1) = *rit;
				*position = val;
				this->_size++;
				return position;
			}

			void
			insert(iterator position, size_type n, const value_type & val)
			{
				if (this->_size + n > this->_capacity)
					this->_realloc(this->_size + n);
				reverse_iterator rend(position + n);
				reverse_iterator rit(this->rbegin());
				for (; rit != rend; rit++)
					*(rit + 1) = *rit;
				for (int i = 0; i < n; i++)
					*(position++) = val;
				this->_size += n;
			}

			template <class InputIterator>
    		void
			insert(iterator position, InputIterator first, InputIterator last)
			{
				size_type n = last - first;
				if (this->_size + n > this->_capacity)
					this->_realloc(this->_size + n);
				reverse_iterator rend(position + n);
				reverse_iterator rit(this->rbegin());
				for (; rit != rend; rit++)
					*(rit + 1) = *rit;
				for (; first != last; first++)
					*(position++) = *first;
				this->_size += n;
			}

			iterator
			erase(iterator position)
			{
				if (position != this->end())
				{
					iterator last(this->back());
					for (; position != last; position++)
						position = *(position + 1);
					this->_destroy_at_end(1);
				}
				return position;
			}

			iterator
			erase(iterator first, iterator last)
			{
				if (last - first != 0)
				{
					iterator end(this->end());
					for (; last != end; last++)
						*(first++) = *last;
					this->_destroy_at_end(last - first);
				}
				return first;
			}

			void
			swap(vector & x)
			{
				std::swap(this->_data, x._data);
				std::swap(this->_capacity, x._capacity);
				std::swap(this->_size, x._size);
			}

			void
			resize(size_type n, value_type val = value_type())
			{
				if (n == this->_size)
					return ;
				if (n < this->_size)
					this->_destroy_at_end(this->_size - n);
				else
				{
					if (n > this->capacity)
						this->_realloc(n);
					this->_construct_at_end(n - this->_size, val);
				}
			}
			
			void
			reserve(size_type n)
			{
				if (n <= this->capacity)
					return ;
				if (n > this->max_size())
					throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
				else
					this->_realloc(n);
			}

			// ---- friend(s) ----
			template <typename _T, typename _Allocator>
			friend std::ostream & operator<<(std::ostream &, vector<_T, _Allocator> const &);

			template <typename _T, typename _Allocator>
			friend void	swap(vector<_T, _Allocator> & x, vector<_T, _Allocator> & y);

			template <typename _T, typename _Allocator>
			friend bool operator==(vector<_T, _Allocator> const & lhs, vector<_T, _Allocator> const & rhs);

			template <typename _T, typename _Allocator>
			friend bool operator<(vector<_T, _Allocator> const & lhs, vector<_T, _Allocator> const & rhs);

			template <typename _T, typename _Allocator>
			friend bool operator<=(vector<_T, _Allocator> const & lhs, vector<_T, _Allocator> const & rhs);

			template <typename _T, typename _Allocator>
			friend bool operator>(vector<_T, _Allocator> const & lhs, vector<_T, _Allocator> const & rhs);

			template <typename _T, typename _Allocator>
			friend bool operator>=(vector<_T, _Allocator> const & lhs, vector<_T, _Allocator> const & rhs);

		private:
			pointer 		_data;
			size_type		_size;
			allocator_type	_alloc;
			size_type		_capacity;

			template <typename InputIterator>
			void
			_construct_at_end(InputIterator first, InputIterator last)
			{
				pointer ptr = this->end();
				for (; first != last; first++)
					this->_alloc.construct(ptr++, *first);
				this->_size += last - first;
			}

			void
			_construct_at_end(size_type n, const_reference val)
			{
				pointer ptr = this->end();
				for (int i = 0; i < n; i++)
					this->_alloc.construct(ptr + i, val);
				this->_size += n;
			}

			void
			_destroy_at_end(size_type n)
			{
				pointer ptr = this->end() - n;
				pointer end = this->end();
				for (; ptr != end; ptr++)
					this->_alloc.destroy(ptr);
				this->_size -= n;
			}

			void
			_realloc(size_type newCapacity)
			{
				size_type newSize = (this->_size < newCapacity ? this->_size : newCapacity);
				pointer newData = this->_alloc.allocate(newCapacity);
				for (int i = 0; i < newSize; i++)
					newData[i] = this->_data[i];
				this->clear();
				this->_alloc.deallocate(this->_data, this->_capacity);
				this->_data = newData;
				this->_size = newSize;
				this->_capacity = newCapacity;
			}

			void
			_grow(void)
			{
				size_type newCapacity;
				if (!this->_size)
					newCapacity = 1;
				else if (this->_size < 20)
					newCapacity = this->_size + this->_size;
				else
					newCapacity = this->_size + this->_size / 2;
				this->_realloc(newCapacity);
			}
	};

	// ---- non-member function(s) ----
	template <typename T, typename Allocator>
	bool
	operator==(vector<T, Allocator> const & lhs, vector<T, Allocator> const & rhs)
	{
		if (lhs._size != rhs._size)
			return false;
		if (!equal(lhs.begin(), lhs.end(), rhs.end()))
			return false;
		return true;
	}

	template <typename T, typename Allocator>
	bool
	operator<(vector<T, Allocator> const & lhs, vector<T, Allocator> const & rhs)
	{
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <typename T, typename Allocator>
	bool
	operator<=(vector<T, Allocator> const & lhs, vector<T, Allocator> const & rhs)
	{
		if (lhs._size > rhs._size)
			return false;
		if (equal(lhs.begin(), lhs.end(), rhs.begin()))
			return true;
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <typename T, typename Allocator>
	bool
	operator>(vector<T, Allocator> const & lhs, vector<T, Allocator> const & rhs)
	{
		return !lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <typename T, typename Allocator>
	bool
	operator>=(vector<T, Allocator> const & lhs, vector<T, Allocator> const & rhs)
	{
		if (lhs._size < rhs._size)
			return false;
		if (equal(lhs.begin(), lhs.end(), rhs.begin()))
			return true;
		return !lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <typename T, typename Allocator>
	void swap(vector<T, Allocator> & x, vector<T, Allocator> & y) { x.swap(y); }

	template <typename _T, typename _Allocator>
	std::ostream &
	operator<<(std::ostream & ostrm, ft::vector<_T, _Allocator> const & rhs)
	{
		std::cout << "capacity:\t" << rhs.capacity() << std::endl;
		std::cout << "size:\t\t" << rhs.size() << std::endl;
		std::cout << "begin:\t\t" << &(*rhs.begin()) << std::endl;
		std::cout << "end:\t\t" << &(*rhs.end()) << std::endl;
		typename ft::vector<_T, _Allocator>::const_iterator it(rhs.begin());
		typename ft::vector<_T, _Allocator>::const_iterator end(rhs.end());
		for (; it != end; it++)
			std::cout << *it << std::endl;
		return ostrm;
	}

}

#endif