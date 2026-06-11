#include "phonebook.hpp"
#include <cctype>
#include <cstdlib>

Phonebook::Phonebook() {
	this->_pbSize = 0;
	this->_inputIndex = 0;
}

int	Phonebook::_ValidIndex(const std::string &input) {
	int	index;

	if (input.length() != 1 || !std::isdigit((unsigned char)input[0]))
		return -1;
	index = std::atoi(input.c_str());
	if (index < 1 || index > this->_pbSize)
		return -1;
	return index;
}

void	Phonebook::_AllDisplay() {
	std::cout << std::setw(MAX_CHAR) << "Index";
	std::cout << " | " << std::setw(MAX_CHAR) << "First Name";
	std::cout << " | " << std::setw(MAX_CHAR) << "Last Name";
	std::cout << " | " << std::setw(MAX_CHAR) << "Nickname" << std::endl;
	for (int i = 0; i < this->_pbSize; i++)
	{
		std::cout << std::setw(MAX_CHAR) << i + 1;
		std::cout << " | " << std::setw(MAX_CHAR) << Truncate(this->_contacts[i].GetFirstName());
		std::cout << " | " << std::setw(MAX_CHAR) << Truncate(this->_contacts[i].GetLastName());
		std::cout << " | " << std::setw(MAX_CHAR) << Truncate(this->_contacts[i].GetNickname());
		std::cout << std::endl;
	}
}

void	Phonebook::_DetailDisplay(const Contact &c) {
	std::cout << "First name    : " << c.GetFirstName( ) << std::endl;
	std::cout << "Last name     : " << c.GetLastName( ) << std::endl;
	std::cout << "Nickname      : " << c.GetNickname( ) << std::endl;
	std::cout << "Phone number  : " << c.GetPhoneNumber( ) << std::endl;
	std::cout << "Darkest secret: " << c.GetDarkestSecret( ) << std::endl;
}

void	Phonebook::PhoneBookSearch() {
	std::string	line;
	int		index = -1;

	if (this->_pbSize == 0)
	{
		std::cout << "Error: The phonebook is empty." << std::endl;
		return ;
	}
	_AllDisplay();
	line = InputWaiting("index: ");
	index = _ValidIndex(line);
	if (index == -1)
	{
		std::cout << "Error: Invalid index." << std::endl;
		return ;
	}
	_DetailDisplay(this->_contacts[index - 1]);
}

bool	Phonebook::_FillFromInput() {
	std::string	firstName, lastName, nickname, phoneNumber, darkestSecret;

	firstName = InputWaiting("first name: ");
	if (!ValidName(firstName))
		return false;
	lastName = InputWaiting("last name: ");
	if (!ValidName(lastName))
		return false;
	nickname = InputWaiting("nickname: ");
	if (!ValidName(nickname))
		return false;
	phoneNumber = InputWaiting("phone number: ");
	if (!ValidNumber(phoneNumber))
		return false;
	darkestSecret = InputWaiting("darkest secret: ");
	if (darkestSecret.empty())
		return false;
	this->_contacts[this->_inputIndex] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	return true;
}

bool	Phonebook::PhoneBookAdd() {
	if (!this->_FillFromInput())
	{
		std::cout << "Error: Failed to add contact." << std::endl;
		return false;
	}
	if (this->_pbSize < MAX_CONTACTS)
		this->_pbSize++;
	if (this->_inputIndex + 1 == MAX_CONTACTS)
		this->_inputIndex = 0;
	else
		this->_inputIndex++;
	return true;
}
