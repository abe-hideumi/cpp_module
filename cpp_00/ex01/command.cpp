#include "phonebook.hpp"

namespace {
	std::string input_waiting(std::string msg) {
		std::string	input;

		std::cout << msg;
		std::getline(std::cin, input);
		return (input);
	}

	std::string truncate(const std::string &s)
	{
		if (s.length() > 10)
			return s.substr(0, 9) + ".";
		return s;
	}
}

bool Contact::ADD() {
	Contact	tmp;

	tmp.first_name = input_waiting("first name: ");
	if (tmp.first_name == "")
		return false;
	tmp.last_name = input_waiting("last name: ");
	if (tmp.last_name == "")
		return false;
	tmp.nickname = input_waiting("nickname: ");
	if (tmp.nickname == "")
		return false;
	tmp.phone_number = input_waiting("phone number: ");
	if (tmp.phone_number == "")
		return false;
	tmp.darkest_secret = input_waiting("darkest secret: ");
	if (tmp.darkest_secret == "")
		return false;
	*this = tmp;
	return true;
}

void Phonebook::SEARCH() {
	if (count == -1)
	{
		std::cout << "The phonebook is empty. Please add a contact first." << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index";
	std::cout << " | " << std::setw(10) << "First Name";
	std::cout << " | " << std::setw(10) << "Last Name";
	std::cout << " | " << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i <= count; i++)
	{
		std::cout << std::setw(10) << i + 1;
		std::cout << " | " << std::setw(10) << truncate(contacts[i].first_name);
		std::cout << " | " << std::setw(10) << truncate(contacts[i].last_name);
		std::cout << " | " << std::setw(10) << truncate(contacts[i].nickname);
		std::cout << std::endl;
	}

	std::string	line;
	int			idx;
	std::cout << "Enter index: ";
	std::getline(std::cin, line);
	std::istringstream ss(line);
	if (!(ss >> idx) || idx < 1 || idx > count + 1)
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	Contact &c = contacts[idx - 1];
	std::cout << "First name    : " << c.first_name << std::endl;
	std::cout << "Last name     : " << c.last_name << std::endl;
	std::cout << "Nickname      : " << c.nickname << std::endl;
	std::cout << "Phone number  : " << c.phone_number << std::endl;
	std::cout << "Darkest secret: " << c.darkest_secret << std::endl;
}

void EXIT() {
	std::cout << "The Program quits and the contacts are lost forever!" << std::endl;
}
