#include <iostream>
#include <memory>
#include <exception>
#include <vector>
#include "vector.hpp"
#include <iterator>
#include <algorithm>
#include <type_traits>
#include "type_traits.hpp"

template <typename T>
void print(T const val) {
    std::cout << val;
}

class Test {
    public:
        typedef int type_t;

        int         x;
        int         y;

        Test(void) {
            std::cout << "constructor\n";
        }

        Test(int const x, int const y) {
            std::cout << "constructor x y\n";
            this->x = x;
            this->y = y;
        }

        Test(Test const & src) {
            this->x = src.x;
            this->y = src.y;
            std::cout << "copy constructor\n";
        }

        ~Test(void) {
            std::cout << "destructor\n";
        }
};

void printTest(Test const & x) {
    std::cout << x.x << "," << x.y << std::endl;
}

template <typename T>
void myFunc(T & value) {
    try {
        std::allocator<T> alloc;
        size_t maxSize = alloc.max_size();
        typename std::allocator<T>::pointer ptr = alloc.allocate(sizeof(value));
        alloc.construct(ptr, value);
        //*ptr = value;
        std::cout << ptr->x << ";" << ptr->y << std::endl;
        alloc.destroy(ptr);
        alloc.deallocate(ptr, sizeof(value));
    } catch (std::bad_alloc & e) {
        std::cerr << e.what() << std::endl;
    }
}

void printInt(int const val) {
    std::cout << val << " ";
}

template <typename T>
void    showInfos(T const & v) {
    std::cout << "------------" << std::endl;
    std::cout << "size: " << v.size() << std::endl;
    std::cout << "capacity: " << v.capacity() << std::endl;
    std::cout << "begin: " << &*(v.begin()) << std::endl;
    std::cout << "tab: ";
    std::for_each(v.begin(), v.end(), &printInt);
    std::cout << std::endl;
}


/*
int main(int ac, char *av[]) {
    (void)ac;
    (void)av;

    std::vector<int> stdVec(10, 3);
    ft::vector<int>  ftVec;

    showInfos<std::vector<int> >(stdVec);
    stdVec.resize(523, 7);
    showInfos<std::vector<int> >(stdVec);
    
    //std::cout << v;
    //system("leaks prog | grep leaked");
    return (0);
}
*/

int bar() {
    return (4);
}

template <typename T>
struct remove_pointer {
    typedef T type;
};

template <typename T>
struct remove_pointer<T *> {
    typedef T type;
};

void doesThrow(void) {
    throw (std::runtime_error("error"));
}

void test(void) {
    int x = 5;
    doesThrow();
    std::cout << x << std::endl;
}

int main() {
    ft::vector<int> v(5, 100);
    //std::for_each(v.begin(), v.end(), &printInt);
    std::cout << v << std::endl;
}

