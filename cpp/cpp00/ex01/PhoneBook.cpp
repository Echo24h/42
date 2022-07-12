#include "PhoneBook.hpp"

void	PhoneBook::addContact(Contact const & contact)
{
	static int n = 0;

	this->contacts[n++] = contact;
	if (n == 8) { n = 0; }
}

void	PhoneBook::search(void) {
	// show all contacts
	std::cout << "|" << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "FirstName" << "|";
	std::cout << std::setw(10) << "LastName" << "|";
	std::cout << std::setw(10) << "Nickname" << "|\n";
	for (int i = 0; i < 8; i++) {
		std::cout << "|" << std::setw(10) << i << "|";

		if (this->contacts[i].firstName.length() > 10) {
			std::cout << this->contacts[i].firstName.substr(0, 9) << ".|";
		} else {
			std::cout << std::setw(10) << this->contacts[i].firstName << "|";
		}

		if (this->contacts[i].lastName.length() > 10) {
			std::cout << this->contacts[i].lastName.substr(0, 9) << ".|";
		} else {
			std::cout << std::setw(10) << this->contacts[i].lastName << "|";
		}

		if (this->contacts[i].nickname.length() > 10) {
			std::cout << this->contacts[i].nickname.substr(0, 9) << ".|\n";
		} else {
			std::cout << std::setw(10) << this->contacts[i].nickname << "|\n";
		}
	}

	// show infos of choosen contact
	int index;
	std::cout << "Select an index: ";
	while (!(std::cin >> index) || !(index >= 0 && index <= 7)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid index, try again noob: ";
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	this->contacts[index].showInfos();
	std::cout << std::endl;
}
