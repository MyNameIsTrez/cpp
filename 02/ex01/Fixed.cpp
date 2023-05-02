#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed()
		: raw_bits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const i) {
	std::cout << "Int constructor called" << std::endl;
	raw_bits = i * (1 << fractional_bit_count);
}

Fixed::Fixed(float const f) {
	std::cout << "Float constructor called" << std::endl;
	raw_bits = f * (1 << fractional_bit_count);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	raw_bits = src.raw_bits;
	return (*this);
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return raw_bits;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	raw_bits = raw;
}

float	Fixed::toFloat(void) const {
	return static_cast<float>(raw_bits) / (1 << fractional_bit_count);
}

int		Fixed::toInt(void) const {
	return raw_bits >> fractional_bit_count;
}

std::ostream&	operator<<(std::ostream &out, Fixed const &f) {
	return out << f.toFloat();
}
