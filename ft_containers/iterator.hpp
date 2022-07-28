#ifndef _iterator_hpp_
#define _iterator_hpp_

#include <iostream>
#include <cstddef>

namespace ft {
	struct	input_iterator_tag {};
	struct	output_iterator_tag {};
	struct	forward_iterator_tag       : public input_iterator_tag {};
	struct	bidirectional_iterator_tag : public forward_iterator_tag {};
	struct	random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <typename Iterator>
	struct iterator_traits {
		typedef Iterator::difference_type	difference_type;
		typedef Iterator::value_type		value_type;
		typedef Iterator::pointer			pointer;
		typedef Iterator::reference			reference;
		typedef Iterator::iterator_category	iterator_category;
	};

	template <typename T>
	struct iterator_traits<T *> {
		typedef ptrdiff_t					difference_type;
		typedef T							value_type;
		typedef T *							pointer;
		typedef T &							reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template <typename T>
	struct iterator_traits<T const *> {
		typedef ptrdiff_t					difference_type;
		typedef T							value_type;
		typedef T const *					pointer;
		typedef T const &					reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template <
		typename Category,
		typename T, 
		typename Distance = ptrdiff_t,
		typename Pointer = T *,
		typename Reference = T &
	>
	struct iterator {
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};
}

#endif