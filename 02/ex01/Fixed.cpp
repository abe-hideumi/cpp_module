#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed( void ) : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( Fixed const & src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed & Fixed::operator=( Fixed const & rhs ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const {
	return this->_fixedPointValue;
}

void Fixed::setRawBits( int const raw ) {
	this->_fixedPointValue = raw;
}

Fixed::Fixed( const int n ) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed( const float n ) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(n * (1 << _fractionalBits));
}

int Fixed::toInt(void) const {
	return this->_fixedPointValue >> _fractionalBits;
}

float Fixed::toFloat(void) const {
	return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

std::ostream &operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
}
