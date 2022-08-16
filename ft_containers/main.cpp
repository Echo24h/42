#include <iostream>
#include <memory>
#include <exception>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>
#include <type_traits>
#include <list>
#include <stack>
#include <map>
#include "vector.hpp"
#include "type_traits.hpp"
#include "iterator.hpp"
#include "utility.hpp"
#include "algorithm.hpp"
#include "stack.hpp"

class Test
{
    public:
        int         x;
        std::string	s;
        int         *w;

        Test(void) 													: x(0), s("") 			{ w = new int(0); }
        Test(int const & x, std::string const & s) 					: x(x), s(s) 			{ w = new int(0); }
        Test(int const & x, std::string const & s, int const & _w) 	: x(x), s(s) 			{ w = new int(_w); }
        Test(Test const & src) 										: x(src.x), s(src.s) 	{ w = new int(*src.w); }

        ~Test(void) { delete this->w; }

        Test & operator=(Test const & src)
        {
            this->x = src.x;
            this->s = src.s;
            *this->w = *src.w;
            return *this;
        }

        friend std::ostream & operator<<(std::ostream & o, Test const & rhs);
};

std::ostream & operator<<(std::ostream & o, Test const & rhs)
{
    std::cout << rhs.x << "," << rhs.s << "," << *rhs.w;
    return o;
}

template <typename T>
std::ostream & operator<<(std::ostream & ostrm, std::vector<T> const & rhs)
{
    std::cout << "capacity:\t" << rhs.capacity() << std::endl;
    std::cout << "size:\t\t" << rhs.size() << std::endl;
    // std::cout << "begin:\t\t" << &(*rhs.cbegin()) << std::endl;
    // std::cout << "end:\t\t" << &(*rhs.cend()) << std::endl;
	std::cout << "data: ";
    typename std::vector<T>::const_iterator it(rhs.cbegin());
    typename std::vector<T>::const_iterator end(rhs.cend());
    for (; it != end; it++)
        std::cout << *it << " ";
	std::cout << std::endl << "--------" << std::endl;
    return ostrm;
}

typedef int	type;

type val1 = 1;
type val2 = 2;
type val3 = 3;
type val4 = 4;
type val5 = 5;

#ifdef STD
typedef std::vector<type>	vector;
#else
typedef ft::vector<int>	vector;
#endif

void print(char const * str) { std::cout << str << std::endl; }

std::vector<type> begin_test(vector vector) {
    std::vector<type> v;
    vector.assign(1000, 1);
    v.push_back(*vector.begin());
    //v.push_back(*++vector.begin());
    return v;
}

template <typename T>
struct iterator
{
	typedef T				type;
	typedef T const			const_type;
	typedef type *			pointer;
	typedef const_type *	const_pointer;

	pointer curr;

	iterator(void) : curr(nullptr) {}
	iterator(pointer ptr) : curr(ptr) {}
	iterator(iterator const & src) : curr(src.curr) {}
	~iterator(void) {}

	iterator & 	operator++(void) 	{ std::cout << "prefix 	++\n"; curr++; return *this; }
	iterator 	operator++(int) 	{ std::cout << "postfix ++h\n"; iterator tmp(*this); curr++; return tmp; }
	iterator & 	operator--(void) 	{ std::cout << "prefix 	--\n"; curr--; return *this; }
	iterator 	operator--(int) 	{ std::cout << "postfix --\n"; iterator tmp(*this); curr--; return tmp; }
	type & 		operator*(void) 	{ return *curr; }

	pointer getCurr(void) { return curr; }
};

template <typename T>
struct toto
{
	typedef T				type;
	typedef T const			const_type;
	typedef type *			pointer;
	typedef const_type *	const_pointer;
	typedef iterator<type>	iterator;

	pointer data;

	toto(void)				{ data = new type[2]; }
	toto(const_type & x) 	{ data = new type[2]; data[0] = x; data[1] = 4; }
	toto(toto const & src) 	{ data = new type[2]; data[0] = src.data[0]; data[0] = src.data[1]; }
	~toto(void)				{ delete[] data; }
	
	iterator 		getData(void) 		{ std::cout << "getData\n"; return iterator(data); }
	const_pointer 	getData(void) const	{ std::cout << "getData const\n"; return data; }
};

int _ratio = 1;

#define TESTED_TYPE 		int
#define	TESTED_NAMESPACE 	ft

int main()
{
	std::list<TESTED_TYPE> lst;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	std::list<TESTED_TYPE>::iterator lst_it = lst.begin();
	std::list<TESTED_TYPE>::iterator end = lst.end();
	std::list<TESTED_TYPE>::difference_type n = distance(lst_it, end);
	std::cout << n << std::endl;
	//TESTED_NAMESPACE::vector<TESTED_TYPE> vct(lst.begin(), lst.end());
	// //printSize(vct);

	// lst_it = lst.begin();
	// for (int i = 1; lst_it != lst.end(); ++i)
	// 	*lst_it++ = i * 5;
	// vct.assign(lst.begin(), lst.end());
	// //printSize(vct);

	// vct.insert(vct.end(), lst.rbegin(), lst.rend());
	//printSize(vct);
	return (0);
}