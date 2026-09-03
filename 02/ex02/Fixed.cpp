#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// --- コンストラクタ / デストラクタ ---
Fixed::Fixed( void ) : _fixedPointValue(0) {}

Fixed::Fixed( Fixed const & src ) {
	*this = src;
}

Fixed::~Fixed( void ) {}

Fixed & Fixed::operator=( Fixed const & rhs ) {
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return *this;
}

Fixed::Fixed( const int n ) {
	this->_fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed( const float n ) {
	this->_fixedPointValue = roundf(n * (1 << _fractionalBits));
}

// --- 変換・ゲッター・セッター ---
int Fixed::getRawBits( void ) const {
	return this->_fixedPointValue;
}

void Fixed::setRawBits( int const raw ) {
	this->_fixedPointValue = raw;
}

int Fixed::toInt(void) const {
	return this->_fixedPointValue >> _fractionalBits;
}

float Fixed::toFloat(void) const {
	return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

// --- 1. 比較演算子 ---
bool Fixed::operator>( Fixed const & rhs ) const {
	return this->_fixedPointValue > rhs.getRawBits();
}

bool Fixed::operator<( Fixed const & rhs ) const {
	return this->_fixedPointValue < rhs.getRawBits();
}

bool Fixed::operator>=( Fixed const & rhs ) const {
	return this->_fixedPointValue >= rhs.getRawBits();
}

bool Fixed::operator<=( Fixed const & rhs ) const {
	return this->_fixedPointValue <= rhs.getRawBits();
}

bool Fixed::operator==( Fixed const & rhs ) const {
	return this->_fixedPointValue == rhs.getRawBits();
}

bool Fixed::operator!=( Fixed const & rhs ) const {
	return this->_fixedPointValue != rhs.getRawBits();
}

// --- 2. 算術演算子 ---
Fixed Fixed::operator+( Fixed const & rhs ) const {
	return Fixed( this->toFloat() + rhs.toFloat() );
}

Fixed Fixed::operator-( Fixed const & rhs ) const {
	return Fixed( this->toFloat() - rhs.toFloat() );
}

Fixed Fixed::operator*( Fixed const & rhs ) const {
	return Fixed( this->toFloat() * rhs.toFloat() );
}

Fixed Fixed::operator/( Fixed const & rhs ) const {
	return Fixed( this->toFloat() / rhs.toFloat() );
}

// --- 3. インクリメント / デクリメント ---
// 前置 ++a
Fixed & Fixed::operator++( void ) {
	this->_fixedPointValue++;
	return *this;
}

// 後置 a++ (int は前置と区別するためのダミー引数)
Fixed Fixed::operator++( int ) {
	Fixed tmp(*this);
	this->_fixedPointValue++;
	return tmp;
}

// 前置 --a
Fixed & Fixed::operator--( void ) {
	this->_fixedPointValue--;
	return *this;
}

// 後置 a--
Fixed Fixed::operator--( int ) {
	Fixed tmp(*this);
	this->_fixedPointValue--;
	return tmp;
}

// --- 4. 静的メンバ関数 (min / max) ---
Fixed & Fixed::min( Fixed & a, Fixed & b ) {
	return (a < b) ? a : b;
}

Fixed const & Fixed::min( Fixed const & a, Fixed const & b ) {
	return (a < b) ? a : b;
}

Fixed & Fixed::max( Fixed & a, Fixed & b ) {
	return (a > b) ? a : b;
}

Fixed const & Fixed::max( Fixed const & a, Fixed const & b ) {
	return (a > b) ? a : b;
}

// --- 出力ストリーム演算子 ---
std::ostream &operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
}
