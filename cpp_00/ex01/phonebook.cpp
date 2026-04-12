#include "phonebook.hpp"
#include <sstream>

std::string	Phonebook::truncate(const std::string &str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	Phonebook::all_display() {
	std::cout << std::setw(10) << "Index";
	std::cout << " | " << std::setw(10) << "First Name";
	std::cout << " | " << std::setw(10) << "Last Name";
	std::cout << " | " << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < pb_size; i++)
	{
		std::cout << std::setw(10) << i + 1;
		std::cout << " | " << std::setw(10) << truncate(contacts[i].first_name_get());
		std::cout << " | " << std::setw(10) << truncate(contacts[i].last_name_get());
		std::cout << " | " << std::setw(10) << truncate(contacts[i].nickname_get());
		std::cout << std::endl;
	}
}

void	Phonebook::detail_display(const Contact &c) {
	std::cout << "First name    : " << c.first_name_get() << std::endl;
	std::cout << "Last name     : " << c.last_name_get() << std::endl;
	std::cout << "Nickname      : " << c.nickname_get() << std::endl;
	std::cout << "Phone number  : " << c.phone_number_get() << std::endl;
	std::cout << "Darkest secret: " << c.darkest_secret_get() << std::endl;
}

void	Phonebook::phonebook_search() {
	std::string	line;
	int		index = -1;

	if (pb_size == 0)
	{
		std::cout << "Error: The phonebook is empty." << std::endl;
		return ;
	}
	all_display();
	line = input_waiting("index: ");
	index = valid_index(pb_size, line);
	if (index == -1)
	{
		std::cout << "Error: Invalid index." << std::endl;
		return ;
	}
	detail_display(contacts[index - 1]);
}

bool	Phonebook::phonebook_add() {
	if (contacts[input_index].fill_from_input() == false)
	{
		std::cout << "Error: Failed to add contact." << std::endl;
		return false;
	}
	if (pb_size < MAX_CONTACTS)
		pb_size++;
	if (input_index + 1 == MAX_CONTACTS)
		input_index = 0;
	else
		input_index++;
	return true;
}
