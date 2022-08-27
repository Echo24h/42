#include <iostream>
#include <memory>
#include <exception>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>
#include <type_traits>
#include <functional>
#include <list>
#include <stack>
#include <map>
#include "vector.hpp"
#include "type_traits.hpp"
#include "iterator.hpp"
#include "utility.hpp"
#include "algorithm.hpp"
#include "stack.hpp"
#include "tree.hpp"
#include <csignal>

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

struct A
{
	A(void) { std::cout << "constructor"; } 
	~A(void) { std::cout << "destructor"; } 
};

typedef int																	type;
typedef ft::BST<type, std::less<type>, std::allocator<type> >	            BST;
typedef ft::vector<type>													vector;


void print_map(std::string_view comment, const std::map<std::string, int>& m)
{
    std::cout << comment ;
    // iterate using C++17 facilities
	std::map<std::string, int>::const_iterator it = m.begin();
	std::map<std::string, int>::const_iterator ite = m.end();
		std::cout << "\nite: " << '[' << ite->first << "] = " << ite->second << "\n";
	for (; it != ite; it++)
		std::cout << '[' << it->first << "] = " << it->second << "; ";
// C++11 alternative:
//  for (const auto& n : m) {
//      std::cout << n.first << " = " << n.second << "; ";
//  }
// C++98 alternative
//  for (std::map<std::string, int>::const_iterator it = m.begin(); it != m.end(); it++) {
//      std::cout << it->first << " = " << it->second << "; ";
//  }
    std::cout << '\n';
}

int main()
{
	// std::map<std::string, int> m { {"CPU", 10}, {"GPU", 15}, {"RAM", 20}, };
	// std::map<std::string, int>::iterator it = m.begin();
	// // --it;
	// ++it;
	// std::cout << it->first << std::endl;
	// return 0;
    // print_map("1) Initial map: ", m);
 
    // m["CPU"] = 25;  // update an existing value
    // m["SSD"] = 30;  // insert a new value
    // print_map("2) Updated map: ", m);
 
    // // using operator[] with non-existent key always performs an insert
    // std::cout << "3) m[UPS] = " << m["UPS"] << '\n';
    // print_map("4) Updated map: ", m);
 
    // m.erase("GPU");
    // print_map("5) After erase: ", m);
 
    // m.clear();
    // std::cout << std::boolalpha << "8) Map is empty: " << m.empty() << '\n';

	BST bst;
	
    bst.insert(6);
	bst.insert(15);
	bst.insert(7);
	bst.insert(13);
	bst.insert(9);
	// // // BST::node_pointer n = bst.find(13);
	// // // std::cout << n->data << std::endl;
	bst.insert(18);
	// bst.erase(15);
	// bst.insert(15);
	// bst.showInOrder();
	BST::iterator it = bst.begin();
	// it.base()->debug("begin");
	// it.base()->right->debug("begin->right");
	BST::iterator ite = bst.end();
	// std::cout << "_end: " << &*ite << std::endl;

	// ite.base()->debug("ite");
	
	// --ite;
	// ite.base()->debug("ite");
	// // std::cout << std::endl;
	// ++it;
	// it.base()->debug("it");
	// ++it;
	// it.base()->debug("it");
	// --it;
	// it.base()->debug("it");
	//std::cout << *it << std::endl;
	// BST::iterator ite = bst.begin();
	// ++ite;
	// std::cout << (it == ite) << std::endl;
	for (; it != ite; --ite)
		std::cout << *ite << std::endl;
    // bst.insert(17);
    // bst.insert(20);
	// BST::iterator it = bst.begin();
	// BST::iterator ite = bst.end();
	// for (; it != ite; ++it)
	// 	std::cout << it->data << std::endl;
	// std::cout << "---\n";
    // // BST::node_pointer nptr = bst.searchNode(4);
	// // BST::iterator it(nptr);
	// // std::cout << nptr->data << std::endl;
	// // std::cout << *it << std::endl;
	return (0);
}
