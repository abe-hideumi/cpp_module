#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <cstdlib>
# include <cctype>
# include <iostream>
# include <iomanip>

const int	MAX_CONTACTS = 8;

class Contact {
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;

	public:
		std::string	get_first_name() const { return first_name; }
		std::string	get_last_name() const { return last_name; }
		std::string	get_nickname() const { return nickname; }
		std::string	get_phone_number() const { return phone_number; }
		std::string	get_darkest_secret() const { return darkest_secret; }
		bool		fill_from_input();
};

class Phonebook {
	private:
		int			pb_size;
		int			input_index;
		Contact		contacts[MAX_CONTACTS];
		std::string	truncate(const std::string &s);
		void		all_display();
		void		detail_display(const Contact &c);

	public:
		Phonebook() : pb_size(0), input_index(0) {}
		bool		phonebook_add();
		void		phonebook_search();
};

void		exit_program(void);
std::string	input_waiting(const std::string &msg);
bool		valid_string(const std::string &input);
bool		valid_number(const std::string &input);
int			valid_index(int pb_size, const std::string &input);

#endif
