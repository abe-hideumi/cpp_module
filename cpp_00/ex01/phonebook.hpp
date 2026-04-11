#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <sstream>

# define MAX_CONTACTS 7
# define OLD_CONTACT -1

class Contact {
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
		bool		ADD();
};

class Phonebook {
	public:
		Contact		contacts[MAX_CONTACTS + 1];
		int			count;
		void		SEARCH();
};

void	EXIT(void);

#endif
