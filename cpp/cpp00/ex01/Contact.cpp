#include "Contact.hpp"
#include <iomanip>

int		Contact::fillInfos(void)
{
	std::cout << "First Name: ";
	std::getline(std::cin, this->firstName);
	if (firstName.empty())
		return (-1);
	std::cout << "Last Name: ";
	std::getline(std::cin, this->lastName);
	if (lastName.empty())
		return (-1);
	std::cout << "nickname: ";
	std::getline(std::cin, this->nickname);
	if (nickname.empty())
		return (-1);
	std::cout << "Phone Number: ";
	std::getline(std::cin, this->_phoneNumber);
	if (_phoneNumber.empty())
		return (-1);
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, this->_darkestSecret);
	if (_darkestSecret.empty())
		return (-1);
	return (0);
}

void	Contact::showInfos()
{
	std::cout << "First Name: " << this->firstName << std::endl;
	std::cout << "Last Name: " << this->lastName << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
}