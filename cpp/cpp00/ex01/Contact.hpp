#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
	private:
		std::string darkestSecret;
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
	public:
		Contact(std::string _firstName = "",
			std::string _lastName = "",
			std::string _nickname = "",
			std::string _phoneNumber = "",
			std::string _darkestSecret = "") {
			firstName = _firstName;
			lastName = _lastName;
			nickname = _nickname;
			phoneNumber = _phoneNumber;
			darkestSecret = _darkestSecret;
		}

		int	fillInfos()
		{
			std::cout << "First Name: ";
			std::getline(std::cin, firstName);
			if (firstName.empty())
				return (-1);
			std::cout << "Last Name: ";
			std::getline(std::cin, lastName);
			if (lastName.empty())
				return (-1);
			std::cout << "Nickname: ";
			std::getline(std::cin, nickname);
			if (nickname.empty())
				return (-1);
			std::cout << "Phone Number: ";
			std::getline(std::cin, phoneNumber);
			if (phoneNumber.empty())
				return (-1);
			std::cout << "Darkest Secret: ";
			std::getline(std::cin, darkestSecret);
			if (darkestSecret.empty())
				return (-1);
			return (0);
		}

		void	showInfosInArray(int index)
		{
			std::cout << "|" << std::setw(10) << index << "|";

			if (firstName.length() > 10)
				std::cout << firstName.substr(0, 9) << ".|";
			else
				std::cout << std::setw(10) << firstName << "|";

			if (lastName.length() > 10)
				std::cout << lastName.substr(0, 9) << ".|";
			else
				std::cout << std::setw(10) << lastName << "|";

			if (nickname.length() > 10)
				std::cout << nickname.substr(0, 9) << ".|\n";
			else
				std::cout << std::setw(10) << nickname << "|\n";
		}

		void	showInfos()
		{
			std::cout << "First Name: " << firstName << std::endl;
			std::cout << "Last Name: " << lastName << std::endl;
			std::cout << "Nickname: " << nickname << std::endl;
			std::cout << "Phone Number: " << phoneNumber << std::endl;
			std::cout << "Darkest Secret: " << darkestSecret << std::endl;
			std::cout << std::endl;
		}
};

#endif
