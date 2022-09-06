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
#include "map.hpp"
#include "tree.hpp"
#include <csignal>

#include <type_traits>
#include <typeinfo>
#ifndef _MSC_VER
#   include <cxxabi.h>
#endif
#include <memory>
#include <string>
#include <cstdlib>

template <class T>
std::string type_name(void)
{
    typedef typename std::remove_reference<T>::type TR;
    std::unique_ptr<char, void(*)(void*)> own
           (
#ifndef _MSC_VER
                abi::__cxa_demangle(typeid(TR).name(), nullptr,
                                           nullptr, nullptr),
#else
                nullptr,
#endif
                std::free
           );
    std::string r = own != nullptr ? own.get() : typeid(TR).name();
    if (std::is_const<TR>::value)
        r += " const";
    if (std::is_volatile<TR>::value)
        r += " volatile";
    if (std::is_lvalue_reference<T>::value)
        r += "&";
    else if (std::is_rvalue_reference<T>::value)
        r += "&&";
    return r;
}

typedef std::string															key_type;
typedef int																	mapped_type;
typedef ft::pair<const std::string, int>									type;
typedef ft::BST<type, std::less<type>, std::allocator<type> >	            bst;
typedef ft::map<key_type, mapped_type>										map;
typedef ft::vector<type>													vec;


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

struct Test
{
	int x;

	Test(int x) : x(x) {}
};

template <typename Map>
void fillMap(Map & m)
{
	m.insert(ft::make_pair(1, 5));
	m.insert(ft::make_pair(2, 8));
	m.insert(ft::make_pair(3, 9));
	m.insert(ft::make_pair(4, 1));
	m.insert(ft::make_pair(5, 2));
}

template <typename Map>
void fillStdMap(Map & m)
{
	m.insert(std::make_pair(1, 5));
	m.insert(std::make_pair(2, 8));
	m.insert(std::make_pair(3, 9));
	m.insert(std::make_pair(4, 1));
	m.insert(std::make_pair(5, 2));
}

template <typename Vector>
void printVec(std::string const & pfx, Vector const & v)
{
    std::cout << pfx << std::endl;
    typename Vector::const_iterator it = v.begin();
    for (; it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

typedef ft::map<int, int>::iterator iterator;
typedef ft::map<int, int>::const_iterator const_iterator;

int main()
{   
	ft::map<int, int> mp;

	// iterator  itz = mp.begin();
	// const_iterator  citz = mp.end();
	//mp.insert(ft::make_pair(1, 3));

	mp.insert(ft::make_pair(6, 3));
	mp.insert(ft::make_pair(5, 3));
	mp.insert(ft::make_pair(3, 3));
	mp.insert(ft::make_pair(4, 3));
	mp.insert(ft::make_pair(2, 3));
	mp.insert(ft::make_pair(1, 3));
	// mp.insert(ft::make_pair(9, 3));
	// mp.insert(ft::make_pair(8, 3));
	// mp.insert(ft::make_pair(7, 3));

	mp.erase(3);
	// iterator it = ++mp.begin();
	// std::cout << it->first << std::endl;
	//mp.erase(mp.begin(), ++mp.begin());
	// mp.erase(--(--(--mp.end())), --mp.end());
	//mp.erase(mp.begin(), ++(--(++mp.begin())));
	//mp.show();
	// for (iterator itx = mp.begin(); itx != ++++++mp.begin(); ++itx)
	// 	std::cout << itx->first << std::endl;

	// for (iterator it = mp.begin(); it != mp.end(); ++it)
	// 	std::cout << it->first << ": " << it->second << std::endl;
    return 0;
}
