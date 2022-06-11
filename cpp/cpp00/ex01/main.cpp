#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main()
{
	std::string	cmd;
	PhoneBook	pb;
	Contact		newContact;

	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD") {
			if (newContact.fillInfos() == -1) {
				std::cout << std::endl;
				std::clog << "Error: field cannot be empty\n";
			}
			else {
				std::cout << std::endl << "Contact added successfully\n";
				pb.addContact(newContact);
			}
		}
		else if (cmd == "SEARCH")
			pb.search();
		else if (cmd == "EXIT")
			break ;
	}
	return (0);
}
