#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include "contact.hpp"
# include "utils.hpp"

# define MAX_CONTACTS 8

class Phonebook {
	private:
		int			_pbSize;
		int			_inputIndex;
		Contact		_contacts[MAX_CONTACTS];
		void		_AllDisplay();
		void		_DetailDisplay(const Contact &c);
		int			_ValidIndex(const std::string &input);
		bool		_FillFromInput();

	public:
		Phonebook();
		bool		PhoneBookAdd();
		void		PhoneBookSearch();
};

#endif
