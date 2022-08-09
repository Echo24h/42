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

	// ---- reverse iterator ----
	template <class Iterator>
	class reverse_iterator {
		public:
			// ---- member type(s) ----
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category 	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;

			// ---- constructor(s) ----
			reverse_iterator(void) {
				this->_base_it = iterator_type();
			}

			explicit reverse_iterator (iterator_type it) {
				this->_base_it = it;
			}

			template <class Iter>
  			reverse_iterator (reverse_iterator<Iter> const & rev_it) {
				this->_base_it = rev_it._base_it;
			}

			// ---- operator(s) ----
			reference operator*(void) const {
				iterator_type it = this->_base_it;
				return (*(--it));
			}

			reverse_iterator operator+(difference_type n) const {
				this->_base_it = this->_base_it - n;
				return (*this);
			}

			reverse_iterator & operator++() {
				this->_base_it--;
				return (*this);
			}

			reverse_iterator operator++(int) {
				reverse_iterator tmp = *this;
				this->_base_it--;
				return (tmp);
			}

			reverse_iterator & operator+=(difference_type n) {
				return (this->_base_it - n);
			}

			reverse_iterator operator-(difference_type n) const {
				return (this->_base_it + n);
			}

			reverse_iterator & operator--() {
				this->_base_it++;
				return (*this);
			}

			reverse_iterator operator--(int) {
				reverse_iterator tmp = *this;
				this->_base_it++;
				return (tmp);
			}

			reverse_iterator & operator-=(difference_type n) {
				this->_base_it += n;
				return (this);
			}

			// ---- member function(s) ----
			iterator_type base(void) const {
				return (this->_base_it);
			}

			pointer operator->(void) const {
				return (&(operator*()));
			}

			reference operator[](difference_type n) const {
				
			}

		private:
			iterator_type _base_it;

	};
}

#endif