#ifndef _map_hpp_
#define _map_hpp_

#include <functional> // * for std::binary_function
#include "utility.hpp"

namespace ft
{
	template <
		typename Key,
        typename T,
        typename Compare = less<Key>,
        typename Alloc = allocator<ft::pair<Key const, T> >
    >
	class map
	{
		public:
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef ft::pair<key_type const, mapped_type> 	value_type;
			typedef Compare									key_compare;
			typedef Alloc									allocator_type;
			typedef allocator_type::reference				reference;
			typedef allocator_type::const_reference			const_reference;
			typedef allocator_type::pointer					pointer;
			typedef allocator_type::const_pointer			const_pointer;
			typedef size_t									size_type;
			// typedef value_compare				Nested function class to compare elements	see value_comp
			// typedef iterator						a bidirectional iterator to value_type	convertible to const_iterator
			// typedef const_iterator				a bidirectional iterator to const value_type	
			// typedef reverse_iterator				reverse_iterator<iterator>	
			// typedef const_reverse_iterator		reverse_iterator<const_iterator>	
			// typedef difference_type				a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t

		private:
			struct _node
			{
				value_type	v;
				_node * 	l;
				_node * 	r;
			}

		public:
			map(void);

			explicit map(const Compare & comp, const Allocator & alloc = Allocator());

			map(const map & other);

			template <typename InputIt>
			map(InputIt first, InputIt last,
				const Compare & comp = Compare(),
				const Allocator & alloc = Allocator() );

			~map(void) {}

			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class map;
				protected:
					key_compare comp;

					value_compare(key_compare c);
					
				public:
					bool operator()(const value_type & x, const value_type & y) const;
			};

	};
}

#endif