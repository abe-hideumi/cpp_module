#include "phonebook.hpp"
#include <cctype>
#include <cstdlib>

int	Phonebook::validIndex(const std::string &input) {
	int	index;

	if (input.length() != 1 || !std::isdigit((unsigned char)input[0]))
		return -1;
	index = std::atoi(input.c_str());
	if (index < 1 || index > this->pbSize)
		return -1;
	return index;
}

void	Phonebook::allDisplay() {
	std::cout << std::setw(10) << "Index";
	std::cout << " | " << std::setw(10) << "First Name";
	std::cout << " | " << std::setw(10) << "Last Name";
	std::cout << " | " << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < this->pbSize; i++)
	{
		std::cout << std::setw(10) << i + 1;
		std::cout << " | " << std::setw(10) << truncate(contacts[i].getFirstName());
		std::cout << " | " << std::setw(10) << truncate(contacts[i].getLastName());
		std::cout << " | " << std::setw(10) << truncate(contacts[i].getNickname());
		std::cout << std::endl;
	}
}

void	Phonebook::detailDisplay(const Contact &c) {
	std::cout << "First name    : " << c.getFirstName() << std::endl;
	std::cout << "Last name     : " << c.getLastName() << std::endl;
	std::cout << "Nickname      : " << c.getNickname() << std::endl;
	std::cout << "Phone number  : " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;
}

void	Phonebook::phonebookSearch() {
	std::string	line;
	int		index = -1;

	if (this->pbSize == 0)
	{
		std::cout << "Error: The phonebook is empty." << std::endl;
		return ;
	}
	allDisplay();
	line = inputWaiting("index: ");
	index = validIndex(line);
	if (index == -1)
	{
		std::cout << "Error: Invalid index." << std::endl;
		return ;
	}
	detailDisplay(contacts[index - 1]);
}

bool	Phonebook::fillFromInput() {
	std::string	firstName, lastName, nickname, phoneNumber, darkestSecret;

	firstName = inputWaiting("first name: ");
	if (!validName(firstName))
		return false;
	lastName = inputWaiting("last name: ");
	if (!validName(lastName))
		return false;
	nickname = inputWaiting("nickname: ");
	if (!validName(nickname))
		return false;
	phoneNumber = inputWaiting("phone number: ");
	if (!validNumber(phoneNumber))
		return false;
	darkestSecret = inputWaiting("darkest secret: ");
	if (darkestSecret.empty())
		return false;
	contacts[inputIndex] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	return true;
}

bool	Phonebook::phonebookAdd() {
	if (!fillFromInput())
	{
		std::cout << "Error: Failed to add contact." << std::endl;
		return false;
	}
	if (this->pbSize < MAX_CONTACTS)
		this->pbSize++;
	if (this->inputIndex + 1 == MAX_CONTACTS)
		this->inputIndex = 0;
	else
		this->inputIndex++;
	return true;
}
