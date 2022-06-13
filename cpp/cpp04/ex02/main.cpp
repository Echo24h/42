#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(int ac, char *av[]) {
	Animal* ptr = new Dog;
	delete ptr;
	return (0);
}
