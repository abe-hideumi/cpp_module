#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Contact {
	public:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
};

class Phonebook {
	public:
	Contact		contacts[8];
	int			count;
};

class Command {
	public:
		void	EXIT(void);
		bool	ADD(Contact *new_contact);
		void	SEARCH(Phonebook *pb);
};

#endif
