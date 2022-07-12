#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>

int	main()
{
	std::string	cmd;
	PhoneBook	pb;

	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD") {
			Contact newContact;
			if (newContact.fillInfos() == -1) {
				std::clog << "Failed to add a new contact, fields cannot be left empty\n";
				std::cout << std::endl;
			}
			else {
				pb.addContact(newContact);
				std::cout << "Contact added successfully\n";
				std::cout << std::endl;
			}
		}
		else if (cmd == "SEARCH")
			pb.search();
		else if (cmd == "EXIT")
			break ;
	}
	return (0);
}
