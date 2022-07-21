#include <iostream>
#include <memory>
#include <exception>
#include <vector>
#include "vector.hpp"
#include <iterator>

class Test {
    public:
        int         x;
        int         y;
};

template <typename T>
void myFunc(T & value) {
    std::allocator<T> alloc;
    try {
        size_t maxSize = alloc.max_size();
        size_t smallerSize = maxSize / 4;
        std::cout << "maxSize: " << maxSize << std::endl;
        std::cout << "smallerSize: " << smallerSize << std::endl;
        typename std::allocator<T>::pointer ptr = alloc.allocate(sizeof(value));
        alloc.construct(ptr, value);
        *ptr = value;
        std::cout << ptr->x << ";" << ptr->y << std::endl;
        alloc.destroy(ptr);
        alloc.deallocate(ptr, sizeof(value));
    } catch (std::bad_alloc & e) {
        std::cerr << e.what() << std::endl;
    }
}

int main(int ac, char *av[]) {
    (void)ac;
    (void)av;

    int x = 5;
    
    Test t;
    myFunc<Test>(t);
    system("leaks prog | grep leaked");
    return (0);
}

/*
4611686018427387904
4611686018427387903

1152921504606846975
*/