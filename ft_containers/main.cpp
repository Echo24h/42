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
    
    std::vector<int> v2(3, 5);
    try {
        std::cout << v2.at(800);
    } catch (std::out_of_range & e) {
        //std::cout << e.what() << std::endl;
    }
    //ft::vector<int> v(5, 3);
    //std::cout << v << std::endl;
    //system("leaks prog | grep leaked");
    return (0);
}
