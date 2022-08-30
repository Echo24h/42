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

template <typename map>
void fillMap(map & m)
{
	m.insert(ft::make_pair("first", 5));
	m.insert(ft::make_pair("second", 8));
	m.insert(ft::make_pair("third", 9));
	m.insert(ft::make_pair("fourth", 1));
	m.insert(ft::make_pair("fifth", 2));
}

typedef map	map;

int main()
{
	std::vector<int> v;
    map mpp;
    fillMap(mpp);
    for (map::iterator it = mpp.begin(); it != mpp.end(); it++) { v.push_back(it->first); }
    for (map::iterator it = --mpp.end(); it != mpp.begin(); it--) { v.push_back(it->first); }
    std::map<int, int> mp0;
    std::map<int, int>::iterator ii = mp0.insert(std::make_pair(3, 3)).first;
    ii++;
    v.push_back((--ii)->first);
    for (int i = 0, j = 10; i < 5; ++i, ++j)
        mp.insert(std::make_pair(i, j));
    map::iterator it = mp.begin();
    map::iterator it2 = mp.end();
    v.push_back(it->first);
    it++;
    it++;
    it++;
    it++;
    v.push_back(it->first);
    it++;
    it--;
    v.push_back(it->first);
    it2--;
    v.push_back(it2->first);
    v.push_back(it2 == it);
    v.push_back((--it2)->first);
    v.push_back((it2--)->first);
    v.push_back((it2++)->first);
    v.push_back((++it2)->first);
	return (0);
}
