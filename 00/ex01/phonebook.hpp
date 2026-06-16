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
		Contact		contacts[MAX_CONTACTS];
		void		AllDisplay();
		void		DetailDisplay(const Contact &c);
		int			ValidIndex(const std::string &input);
		bool		FillFromInput();

	public:
		Phonebook();
		bool		PhonebookAdd();
		void		PhonebookSearch();
};

#endif
