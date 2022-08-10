#ifndef _iterator_hpp_
#define _iterator_hpp_

#include <iostream>
#include <cstddef>

namespace ft {
	// ---- iterator tags ----
	struct	input_iterator_tag {};
	struct	output_iterator_tag {};
	struct	forward_iterator_tag       : public input_iterator_tag {};
	struct	bidirectional_iterator_tag : public forward_iterator_tag {};
	struct	random_access_iterator_tag : public bidirectional_iterator_tag {};

	// ---- iterator_traits ----
	template <typename Iterator>
	struct iterator_traits {
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
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

	template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};

	// ---- reverse iterator ----
	template <class Iterator>
	class reverse_iterator: public iterator<typename iterator_traits<Iterator>::iterator_category,
                      						typename iterator_traits<Iterator>::value_type,
                      						typename iterator_traits<Iterator>::difference_type,
                      						typename iterator_traits<Iterator>::pointer,
                     						typename iterator_traits<Iterator>::reference>
	{
		public:
			// ---- member type(s) ----
			typedef Iterator                                            iterator_type;
			typedef typename iterator_traits<Iterator>::difference_type difference_type;
			typedef typename iterator_traits<Iterator>::reference       reference;
			typedef typename iterator_traits<Iterator>::pointer         pointer;

			// ---- constructor(s) ----
			reverse_iterator(void) {
				this->_curr = iterator_type();
			}

			explicit reverse_iterator(iterator_type it) {
				this->_curr = it;
			}

			template <class Iter>
  			reverse_iterator(reverse_iterator<Iter> const & src) {
				this->_curr = src._curr;
			}

			// ---- operator(s) ----
			reference operator*(void) const {
				iterator_type tmp = this->_curr;
				return (*(--tmp));
			}

			reverse_iterator operator+(difference_type n) const {
				return (reverse_iterator(this->_curr - n));
			}

			reverse_iterator & operator++() {
				this->_curr--;
				return (*this);
			}

			reverse_iterator operator++(int) {
				reverse_iterator tmp(*this);
				this->_curr--;
				return (tmp);
			}

			reverse_iterator & operator+=(difference_type n) {
				this->_curr -= n;
				return (*this);
			}

			reverse_iterator operator-(difference_type n) const {
				return (reverse_iterator(this->_curr + n));
			}

			reverse_iterator & operator--() {
				this->_curr++;
				return (*this);
			}

			reverse_iterator operator--(int) {
				reverse_iterator tmp(*this);
				this->_curr++;
				return (tmp);
			}

			reverse_iterator & operator-=(difference_type n) {
				this->_curr += n;
				return (*this);
			}

			// ---- member function(s) ----
			iterator_type base(void) const {
				return (this->_curr);
			}

			pointer operator->(void) const {
				return (&(operator*()));
			}

			reference operator[](difference_type n) const {
				
			}

		private:
			iterator_type _curr;

	};
}

#endif