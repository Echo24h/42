#ifndef _MutantStack_hpp_
#define _MutantStack_hpp_

#include <iostream>
#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container> {
	public:
		typedef typename Container::iterator	iterator;

	public:
		MutantStack(void)	{}
		~MutantStack(void)	{}

		iterator	begin()	{ return (this->c.begin()); }
		iterator	end() 	{ return (this->c.end()); }

	private:
	
};

#endif
