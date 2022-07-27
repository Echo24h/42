#include <iostream>
#include <memory>
#include <exception>
#include <vector>
#include "vector.hpp"
#include <iterator>
#include <algorithm>

template <typename T>
void print(T const val) {
    std::cout << val;
}

class Test {
    public:
        int         x;
        int         y;

        Test(void) {
            std::cout << "constructor\n";
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
    std::cout << val;
}

int main(int ac, char *av[]) {
    (void)ac;
    (void)av;

    int x = 5;
    std::size_t y = 3;
    
    ft::vector<int> v(y, x);
    std::vector<int> v2(y, x);
    std::for_each(v2.begin(), v2.end(), &printInt);
    std::cout << std::endl;
    std::cout << v;
    //system("leaks prog | grep leaked");
    return (0);
}
