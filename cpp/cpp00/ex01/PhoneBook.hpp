#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];

		int	getIndex() {
			int	index;

			std::cout << "Enter an index: ";
			if(!(std::cin >> index) || index < 0 || index >= 8)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return (-1);
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return (index);
		}

	public:
		PhoneBook() {}

		void addContact(Contact& ref)
		{
			static int n = 0;

			contacts[n++] = ref;
			if (n == 8)
				n = 0;
		}

		void search() {
			std::cout << "|" << std::setw(10) << "Index" << "|";
			std::cout << std::setw(10) << "FirstName" << "|";
			std::cout << std::setw(10) << "LastName" << "|";
			std::cout << std::setw(10) << "Nickname" << "|\n";
			for (int i = 0; i < 8; i++) {
				contacts[i].showInfosInArray(i);
			}
			int index = getIndex();
			std::cout << "\n";
			if (index == -1) {
				std::clog << "Invalid index\n";
			}
			else {
				contacts[index].showInfos();	
			}
		}
};

#endif
