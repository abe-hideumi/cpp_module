#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:
		Contact() {}
		Contact(const std::string &fn, const std::string &ln, const std::string &nn,
				const std::string &pn, const std::string &ds)
			: firstName(fn), lastName(ln), nickname(nn), phoneNumber(pn), darkestSecret(ds) {}
		const std::string &	getFirstName() const { return firstName; }
		const std::string &	getLastName() const { return lastName; }
		const std::string &	getNickname() const { return nickname; }
		const std::string &	getPhoneNumber() const { return phoneNumber; }
		const std::string &	getDarkestSecret() const { return darkestSecret; }
};

#endif
