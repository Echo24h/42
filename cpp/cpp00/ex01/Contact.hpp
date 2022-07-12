#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
	// private variables
	private:
		std::string _darkestSecret;		
		std::string _phoneNumber;

	// public variables
	public:
		std::string firstName;
		std::string lastName;
		std::string	nickname;

	// member function(s)
	public:
		int		fillInfos(void);
		void	showInfos();
};

#endif
