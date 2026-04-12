#include "phonebook.hpp"

bool Contact::fill_from_input() {
	Contact	tmp;

	tmp.first_name = input_waiting("first name: ");
	if (valid_string(tmp.first_name) == false)
		return false;
	tmp.last_name = input_waiting("last name: ");
	if (valid_string(tmp.last_name) == false)
		return false;
	tmp.nickname = input_waiting("nickname: ");
	if (valid_string(tmp.nickname) == false)
		return false;
	tmp.phone_number = input_waiting("phone number: ");
	if (valid_number(tmp.phone_number) == false)
		return false;
	tmp.darkest_secret = input_waiting("darkest secret: ");
	if (valid_string(tmp.darkest_secret) == false)
		return false;
	*this = tmp;
	return true;
}
