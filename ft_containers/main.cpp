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

#define NAMESPACE ft
#define _map NAMESPACE::map
#define _make_pair NAMESPACE::make_pair
#define _pair NAMESPACE::pair

typedef int T;
typedef int V; 

int main()
{   
    _map<T, V, std::plus<int> > mmm;
    mmm.insert(ft::make_pair(5, 1));
    mmm.insert(ft::make_pair(4, 1));
    mmm.insert(ft::make_pair(3, 1));
    mmm.insert(ft::make_pair(2, 1));
    mmm.insert(ft::make_pair(1, 1));
    mmm.show();
    // for (_map<T, V, std::plus<int> >::iterator it = mmm.begin(); it != mmm.end(); ++it)
    //     std::cout << it->first << ": " << it->second << std::endl;
    return 0;

    _map<T, V> mp;
    std::vector<int> v;
    fillMap(mp);
    for (_map<T, V>::iterator it = mp.begin(); it != mp.end(); it++) { v.push_back(it->first); }
    for (_map<T, V>::iterator it = --mp.end(); it != mp.begin(); it--) { v.push_back(it->first); }
    _map<int, int, std::greater<int> > mp1;
    fillMap(mp1);
    v.push_back(mp1.begin()->first);
    mp1.erase(41);
    v.push_back(mp1.begin()->first);
    mp1.erase(29);
    v.push_back(mp1.begin()->first);
    _map<int, int, std::greater<int> > mp2;
    mp2.insert(_make_pair(3, 3));
    v.push_back(mp2.begin()->first);
    mp2.erase(3);
    if (mp2.begin() == mp2.end())
        v.push_back(1);
    std::cout << "prout\n";
    _map<int, int, std::plus<int> > mp3;
    fillMap(mp3);
    for (_map<T, V>::iterator it = mp3.begin(); it != mp3.end(); ++it)
        std::cout << it->first << ": " << it->second << std::endl;
    std::cout << "prout\n";
    for (_map<T, V>::iterator it = mp3.begin(); it != mp3.end(); it++) { std::cout << "zz\n"; v.push_back(it->first); }
    std::cout << "prout\n";
    for (_map<T, V>::iterator it = --mp3.end(); it != mp3.begin(); it--) { v.push_back(it->first); }
    _map<int, int, std::minus<int> > mp4;
    fillMap(mp4);
    for (_map<T, V>::iterator it = mp4.begin(); it != mp4.end(); it++) { v.push_back(it->first); }
    for (_map<T, V>::iterator it = --mp4.end(); it != mp4.begin(); it--) { v.push_back(it->first); }
    _map<int, int, std::greater_equal<int> > mp5;
    fillMap(mp5);
    for (_map<T, V>::iterator it = mp5.begin(); it != mp5.end(); it++) { v.push_back(it->first); }
    for (_map<T, V>::iterator it = --mp5.end(); it != mp5.begin(); it--) { v.push_back(it->first); }
    _map<int, int, std::multiplies<int> > mp6;
    fillMap(mp6);
    for (_map<T, V>::iterator it = mp6.begin(); it != mp6.end(); it++) { v.push_back(it->first); }
    for (_map<T, V>::iterator it = --mp6.end(); it != mp6.begin(); it--) { v.push_back(it->first); }
    _map<int, int, std::bit_xor<int> > mp7;
    fillMap(mp7);
    for (_map<T, V>::iterator it = mp7.begin(); it != mp7.end(); it++) { v.push_back(it->first); }
    for (_map<T, V>::iterator it = --mp7.end(); it != mp7.begin(); it--) { v.push_back(it->first); }
    std::map<T, V, std::logical_and<int> > mp8;
    fillStdMap(mp8);
    for (std::map<T, V>::iterator it = mp8.begin(); it != mp8.end(); it++) { v.push_back(it->first); }
    for (std::map<T, V>::iterator it = --mp8.end(); it != mp8.begin(); it--) { v.push_back(it->first); }
    v.push_back(mp1.size());

    printVec("v:", v);
    return 0;
}
