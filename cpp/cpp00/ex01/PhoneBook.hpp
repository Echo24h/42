#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];

	public:
		void	addContact(Contact const & contact);
		void	search(void);
};

#endif
