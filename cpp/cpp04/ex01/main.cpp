#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(int ac, char *av[]) {
	(void)ac;
	(void)av;
	
	Animal * animals[2];

	for (int i = 0; i < 2; i++) {
		if (i % 2) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
	}

	for (int i = 0; i < 2; i++) {
		delete animals[i];
	}

	Dog d;
	d.addIdea("1");
	d.addIdea("2");
	for (int i = 0; i < 3; i++) {
		d.showIdea(i);
	}

	
	Dog g = d;
	for (int i = 0; i < 3; i++) {
		g.showIdea(i);
	}
	

	return (0);
}
