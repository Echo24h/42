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
typedef ft::BinarySearchTree<type, std::less<type>, std::allocator<type> >	BST;

// int main()
// {
// 	const BST bst(1);
// 	BST::const_node_pointer ptr = bst.searchNode(1);
// 	BST::const_node_pointer child = ptr->getChild();
// 	std::cout << "1:" << ptr->data << std::endl;
// 	// bst.insert(3);
// 	// bst.insert(7);
// 	// bst.insert(8);
// 	// bst.insert(2);
// 	// bst.insert(4);
// 	bst.showInOrder();
// 	std::cout << "---\n";
// 	//bst.deleteNode(3);
// 	//bst.showInOrder();
// 	std::cout << bst.size() << std::endl;
// 	return (0);
// }

int main()
{
	int * i = nullptr;
	int * & refi = i;
	return 0;
	    std::map<std::string, int> mapOfWordCount;
    // Insert Element in map
    mapOfWordCount.insert(std::pair<std::string, int>("first", 1));
    mapOfWordCount.insert(std::pair<std::string, int>("second", 2));
    mapOfWordCount.insert(std::pair<std::string, int>("third", 3));
    mapOfWordCount.insert(std::pair<std::string, int>("v", 4));
    mapOfWordCount.insert(std::pair<std::string, int>("u", 5));
    // Create a map iterator and point to beginning of map
    std::map<std::string, int>::iterator it = mapOfWordCount.begin();
    // Iterate over the map using Iterator till end.
    while (it != mapOfWordCount.end())
    {
        // Accessing KEY from element pointed by it.
        std::string word = it->first;
        // Accessing VALUE from element pointed by it.
        int count = it->second;
        std::cout << word << " :: " << count << std::endl;
        // Increment the Iterator to point to next entry
        it++;
    }
    return 0;
}