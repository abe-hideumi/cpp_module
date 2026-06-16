#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

	public:
		Contact();
		Contact(const std::string &fn, const std::string &ln, const std::string &nn,
				const std::string &pn, const std::string &ds);
		const std::string &	GetFirstName() const;
		const std::string &	GetLastName() const;
		const std::string &	GetNickname() const;
		const std::string &	GetPhoneNumber() const;
		const std::string &	GetDarkestSecret() const;
};

#endif
