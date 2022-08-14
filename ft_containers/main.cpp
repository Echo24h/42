#include <iostream>
#include <memory>
#include <exception>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>
#include <type_traits>
#include "ft.hpp"
#include "colorfull.hpp"

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

// class B {
// public:
//     char *l;
//     int i;
//     B():l(nullptr), i(1) {};
//     B(const int &ex) {
//         this->i = ex;
//         this->l = new char('a');
//     };
//     virtual ~B() {
//         delete this->l;
//         this->l = nullptr;
//     };
// };

// class A : public B {
// public:
//     A():B(){};
//     A(const int &ex) {
//         this->i = ex;
//         this->l = new char('a');
//     };
//     A(const B* ex){
//         this->l = new char(*(ex->l));
//         this->i = ex->i;
//         if (ex->i == -1) throw "n";
//     }
//     ~A() {
//         delete this->l;
//         this->l = nullptr;
//     };
// };

// template <typename T>
// std::vector<int> insert_test_3(std::vector<T> vector) {
//     std::cout << "STD\n";
//     std::vector<int> v;
//     std::vector<int> tmp;
//     tmp.assign(2600 * _ratio, 1);
//     vector.assign(4200 * _ratio, 1);
//     vector.insert(vector.end() - 1000 * _ratio, tmp.begin(), tmp.end());
//     v.push_back(vector[3]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());

//     std::unique_ptr<A> k2(new A(3));
//     std::unique_ptr<A> k3(new A(4));
//     std::unique_ptr<A> k4(new A(-1));
//     std::vector<A> vv;
//     std::vector<B*> v1;

//     v1.push_back(&(*k2));
//     v1.push_back(&(*k3));
//     v1.push_back(&(*k4));
//     try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
//     catch (...) {
//         v.push_back(vv.size());
//         v.push_back(vv.capacity());
//     }

//     return v;
// }

// template <typename T>
// std::vector<int> insert_test_3(ft::vector<T> vector) {
//     std::cout << "FT\n";
//     std::vector<int> v;
//     ft::vector<T> tmp;
//     tmp.assign(2600 * _ratio, 1);
//     vector.assign(4200 * _ratio, 1);
//     vector.insert(vector.end() - 1000 * _ratio, tmp.begin(), tmp.end());
//     v.push_back(vector[3]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
   
//     std::unique_ptr<B> k2(new B(3));
//     std::unique_ptr<B> k3(new B(4));
//     std::unique_ptr<B> k4(new B(-1));
//     ft::vector<B *> vv;
//     ft::vector<A> v1;
    
//     //std::cout << v;
//     v1.push_back(&(*k2));
//     v1.push_back(&(*k3));
//     v1.push_back(&(*k4));
//     std::cout << "pute\n";
//     try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
//     catch (...) {
//         v.push_back(vv.size());
//         v.push_back(vv.capacity());
//     }
//     std::cout << "pute\n";

//     return v;
// }

class Foo
{
public:
    std::string& Name()
    {
        std::cout << "non-const Name\n";
        m_maybe_modified = true;
        return m_name;
    }

    const std::string& Name() const
    {
        std::cout << "const Name\n";
        return m_name;
    }
public:
    std::string m_name;
    bool m_maybe_modified;
};



int main()
{
    ft::vector<int> vector;
    std::vector<int> v;
    vector.assign(1100 * _ratio, 11);
    ft::vector<int> tmp(500 * _ratio, 5), tmp2(1000 * _ratio, 10), tmp3(1500 * _ratio, 15), tmp4(3000 * _ratio, 30);
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    long *adr1 = reinterpret_cast<long *>(&vector);
    long *adr2 = reinterpret_cast<long *>(&tmp);
    vector.swap(tmp);
    if (reinterpret_cast<long *>(&vector) == adr1 && reinterpret_cast<long *>(&tmp) == adr2)
    	v.push_back(1);
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.swap(tmp3);
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    std::cout << tmp2;
    std::cout << vector;
    std::swap(vector, tmp2);
    std::cout << "AFTER SWAP\n";
    std::cout << tmp2;
    std::cout << vector;
    v.push_back(vector[2]);
    std::cout << vector;
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    std::swap(vector, tmp4);
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    std::cout << v;
    return 0;
}

// #ifdef STD
// std::cout << "**** Testing STD ****" << std::endl;
// #else
// std::cout << "**** Testing FT ****" << std::endl;
// #endif