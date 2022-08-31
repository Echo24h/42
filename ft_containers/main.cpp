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

template <typename Vector>
void printVec(std::string const & pfx, Vector const & v)
{
    std::cout << pfx << std::endl;
    typename Vector::const_iterator it = v.begin();
    for (; it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}



typedef ft::map<int, int>   map_type;

template <typename T>
class MyType
{       
    public:
        T i;
        MyType(T i1): i(i1) {}
        MyType(MyType const & other) : i(other.i) {}
        // operator MyTypeConst<T>(void) const { return MyTypeConst<T>(i); }
};

template <typename T>
class MyTypeConst
{ 
    public:
        T i;
        MyTypeConst(T i1): i(i1) {}
        MyTypeConst(MyTypeConst & other) : i(other.i) {}
        MyTypeConst(MyType<T> const & other) : i(other.i) {}
};

template <typename T>
struct myptr
{
    T * ptr;

    myptr(T const & val) { ptr = new T(val); }
    myptr(myptr const & other) { ptr = new T(*other.ptr); }
    ~myptr() { delete ptr; }
};

template <typename T>
class MyTypeUnique
{
    public:
        typedef T   data;
        myptr<T> ptr;
        MyTypeUnique(T i1): ptr(i1) {}
        MyTypeUnique(MyTypeUnique const & other) : ptr(other.ptr) {}
        MyTypeUnique operator=(MyTypeUnique const & other) { ptr = other.ptr; return *this; }
        operator MyTypeUnique<T const>(void) const { return MyTypeUnique<T const>(*ptr.ptr); }
};

int main()
{   
    MyTypeUnique<int> n(5);
    MyTypeUnique<int const> cn(2);

    std::cout << "n: " << *(n.ptr.ptr) << std::endl;
    std::cout << "cn: " << *(cn.ptr.ptr) << std::endl;

    cn = n;

    std::cout << "--------\n";
    std::cout << "n: " << *(n.ptr.ptr) << std::endl;
    std::cout << "cn: " << *(cn.ptr.ptr) << std::endl;

    // map_type mm;
    // fillMap(mm);
    // map_type::iterator it;
    // map_type::const_iterator cit;
    // // cit = it;

    // std::cout << type_name<decltype(it)>() << std::endl;
    // std::cout << type_name<decltype(cit)>() << std::endl;
    
    // std::map<int, int>::iterator stdit;
    // std::map<int, int>::const_iterator stdcit;
    // stdcit = stdit;
    
    // for (; it != mm.end(); ++it)
    //     std::cout << it->first << ": " << it->second << std::endl;

    // map_type mp;
	// std::vector<int> v;
    // map_type mpp;
    // fillMap(mpp);
    // for (map_type::iterator it = mpp.begin(); it != mpp.end(); it++) { v.push_back(it->first); }
    // for (map_type::iterator it = --mpp.end(); it != mpp.begin(); it--) { v.push_back(it->first); }
    // std::map<int, int> mp0;
    // std::map<int, int>::iterator ii = mp0.insert(std::make_pair(3, 3)).first;
    // ii++;
    // v.push_back((--ii)->first);
    // for (int i = 0, j = 10; i < 5; ++i, ++j)
    //     mp.insert(ft::make_pair(i, j));
    // map_type::iterator it = mp.begin();
    // map_type::iterator it2 = mp.end();
    // v.push_back(it->first);
    // it++;
    // it++;
    // it++;
    // it++;
    // v.push_back(it->first);
    // it++;
    // it--;
    // v.push_back(it->first);
    // it2--;
    // v.push_back(it2->first);
    // v.push_back(it2 == it);
    // v.push_back((--it2)->first);
    // v.push_back((it2--)->first);
    // v.push_back((it2++)->first);
    // v.push_back((++it2)->first);
    // printVec("v:", v);
}
