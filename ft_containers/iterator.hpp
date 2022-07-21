#ifndef _iterator_hpp_
#define _iterator_hpp_

#include <iostream>

struct	input_iterator_tag {};
struct	output_iterator_tag {};
struct	forward_iterator_tag       : public input_iterator_tag {};
struct	bidirectional_iterator_tag : public forward_iterator_tag {};
struct	random_access_iterator_tag : public bidirectional_iterator_tag {};

class iterator {
	public:
		iterator(void);
		iterator(iterator const & src);
		~iterator(void);
		iterator & operator=(iterator const & rhs);
	
	private:
	
};

#endif
