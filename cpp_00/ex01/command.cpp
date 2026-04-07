#include "phonebook.hpp"

static std::string Input_waiting(std::string msg) {
	std::string	input;

	std::cout << msg;
	std::getline(std::cin, input);
	return (input);
}

bool Command::ADD(Contact *new_contact) {

	new_contact->first_name = Input_waiting("first name: ");
	if (new_contact->first_name == "")
		return false;
	new_contact->last_name = Input_waiting("last name: ");
	if (new_contact->last_name == "")
		return false;
	new_contact->nickname = Input_waiting("nickname: ");
	if (new_contact->nickname == "")
		return false;
	new_contact->phone_number = Input_waiting("phone number: ");
	if (new_contact->phone_number == "")
		return false;
	new_contact->darkest_secret = Input_waiting("darkest secret: ");
	if (new_contact->darkest_secret == "")
		return false;
	return true;
}

static std::string truncate(const std::string &s)
{
	if (s.length() > 10)
		return s.substr(0, 9) + ".";
	return s;
}

void Command::SEARCH(Phonebook *pb) {
	if (pb->count == -1)
	{
		std::cout << "The phonebook is empty. Please add a contact first." << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index";
	std::cout << " | " << std::setw(10) << "First Name";
	std::cout << " | " << std::setw(10) << "Last Name";
	std::cout << " | " << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i <= pb->count; i++)
	{
		std::cout << std::setw(10) << i + 1;
		std::cout << " | " << std::setw(10) << truncate(pb->contacts[i].first_name);
		std::cout << " | " << std::setw(10) << truncate(pb->contacts[i].last_name);
		std::cout << " | " << std::setw(10) << truncate(pb->contacts[i].nickname);
		std::cout << std::endl;
	}
	return ;
}

void Command::EXIT() {
	std::cout << "The Program quits and the contacts are lost forever!" << std::endl;
	return ;
}
