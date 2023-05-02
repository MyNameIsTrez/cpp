#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed()
		: raw_bits(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const i) {
	// std::cout << "Int constructor called" << std::endl;
	raw_bits = i * (1 << fractional_bit_count);
}

Fixed::Fixed(float const f) {
	// std::cout << "Float constructor called" << std::endl;
	raw_bits = f * (1 << fractional_bit_count);
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const &src) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	raw_bits = src.raw_bits;
	return (*this);
}

int		Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return raw_bits;
}

void	Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;
	raw_bits = raw;
}

float	Fixed::toFloat(void) const {
	return static_cast<float>(raw_bits) / (1 << fractional_bit_count);
}

int		Fixed::toInt(void) const {
	return raw_bits >> fractional_bit_count;
}

Fixed&	Fixed::operator+=(Fixed const &rhs) {
	raw_bits += rhs.raw_bits;
	return *this;
}

Fixed&	Fixed::operator-=(Fixed const &rhs) {
	raw_bits -= rhs.raw_bits;
	return *this;
}

Fixed&	Fixed::operator*=(Fixed const &rhs) {
	raw_bits *= rhs.raw_bits;
	raw_bits >>= fractional_bit_count;
	return *this;
}

Fixed&	Fixed::operator/=(Fixed const &rhs) {
	raw_bits <<= fractional_bit_count;
	raw_bits /= rhs.raw_bits;
	return *this;
}

// Prefix increment
Fixed&	Fixed::operator++() {
	raw_bits++;
	return *this;
}

// Postfix increment
Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);
	operator++();
	return tmp;
}

// Prefix decrement
Fixed&	Fixed::operator--() {
	raw_bits--;
	return *this;
}

// Postfix decrement
Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);
	operator--();
	return tmp;
}

Fixed&	Fixed::min(Fixed &lhs, Fixed &rhs) {
	if (lhs < rhs) {
		return lhs;
	}
	return rhs;
}

Fixed const&	Fixed::min(Fixed const &lhs, Fixed const &rhs) {
	if (lhs < rhs) {
		return lhs;
	}
	return rhs;
}

Fixed&	Fixed::max(Fixed &lhs, Fixed &rhs) {
	if (lhs > rhs) {
		return lhs;
	}
	return rhs;
}

Fixed const&	Fixed::max(Fixed const &lhs, Fixed const &rhs) {
	if (lhs > rhs) {
		return lhs;
	}
	return rhs;
}

std::ostream&	operator<<(std::ostream &out, Fixed const &f) {
	return out << f.toFloat();
}

bool	operator==(Fixed const &lhs, Fixed const &rhs) {
	return lhs.getRawBits() == rhs.getRawBits();
}

bool	operator!=(Fixed const &lhs, Fixed const &rhs) {
	return !(lhs == rhs);
}

bool	operator<(Fixed const &lhs, Fixed const &rhs) {
	return lhs.getRawBits() < rhs.getRawBits();
}

bool	operator>(Fixed const &lhs, Fixed const &rhs) {
	return rhs < lhs;
}

// 3 <= 4 -> !(3 > 4) -> !(0) -> 1
// 4 <= 4 -> !(4 > 4) -> !(0) -> 1
// 5 <= 4 -> !(5 > 4) -> !(1) -> 0
bool	operator<=(Fixed const &lhs, Fixed const &rhs) {
	return !(lhs > rhs);
}

bool	operator>=(Fixed const &lhs, Fixed const &rhs) {
	return !(lhs < rhs);
}

Fixed	operator+(Fixed lhs, Fixed const &rhs) {
	lhs += rhs;
	return lhs;
}

Fixed	operator-(Fixed lhs, Fixed const &rhs) {
	lhs -= rhs;
	return lhs;
}

Fixed	operator*(Fixed lhs, Fixed const &rhs) {
	lhs *= rhs;
	return lhs;
}

Fixed	operator/(Fixed lhs, Fixed const &rhs) {
	lhs /= rhs;
	return lhs;
}
