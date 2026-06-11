#include "contact.hpp"

Contact::Contact() {
	_firstName = "";
	_lastName = "";
	_nickname = "";
	_phoneNumber = "";
	_darkestSecret = "";
}

Contact::Contact(const std::string &fn, const std::string &ln, const std::string &nn,
				 const std::string &pn, const std::string &ds) {
	_firstName = fn;
	_lastName = ln;
	_nickname = nn;
	_phoneNumber = pn;
	_darkestSecret = ds;
}

const std::string &Contact::GetFirstName() const {
	return _firstName;
}

const std::string &Contact::GetLastName() const {
	return _lastName;
}

const std::string &Contact::GetNickname() const {
	return _nickname;
}

const std::string &Contact::GetPhoneNumber() const {
	return _phoneNumber;
}

const std::string &Contact::GetDarkestSecret() const {
	return _darkestSecret;
}
