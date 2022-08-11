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
        int         y;
        int         *w;

        Test(void)
        {
            ft::colorfull("constructor\n", GREEN);
            this->x = 0;
            this->y = 0;
            this->w = new int(0);
        }

        Test(int const x, int const y)
        {            
            ft::colorfull("constructor x y\n", GREEN);
            this->x = x;
            this->y = y;
            this->w = new int(0);
        }

        Test(int const x, int const y, int const w)
        {
            ft::colorfull("constructor x y w\n", GREEN);
            this->x = x;
            this->y = y;
            this->w = new int(w);
        }

        Test(Test const & src)
            : x(src.x), y(src.y), w(nullptr)
        {
            ft::colorfull("copy constructor\n", GREEN);
            //this->x = src.x;
            //this->y = src.y;
            w = new int();
        }

        ~Test(void)
        {
            ft::colorfull("destructor\n", RED);
            delete this->w;
        }

        Test &
        operator=(Test const & src)
        {
            ft::colorfull("operator=\n", YELLOW);
            this->x = src.x;
            this->y = src.y;
            *this->w = *src.w;
            return *this;
        }

        friend std::ostream & operator<<(std::ostream & o, Test const & rhs);
};

std::ostream & operator<<(std::ostream & o, Test const & rhs)
{
    std::cout << rhs.x << "," << rhs.y << "," << *rhs.w;
    return o;
}

template <typename T>
std::ostream &
operator<<(std::ostream & ostrm, std::vector<T> const & rhs)
{
    std::cout << "capacity:\t" << rhs.capacity() << std::endl;
    std::cout << "size:\t\t" << rhs.size() << std::endl;
    std::cout << "begin:\t\t" << &(*rhs.cbegin()) << std::endl;
    std::cout << "end:\t\t" << &(*rhs.cend()) << std::endl;
    typename std::vector<T>::const_iterator it(rhs.cbegin());
    typename std::vector<T>::const_iterator end(rhs.cend());
    for (; it != end; it++)
        std::cout << *it << std::endl;
    return ostrm;
}

int main() {
    int x = 53;
    ft::vector<int> v(5, x);
    std::cout << v;
    return 0;
}
