#pragma once

#include <iostream>

// Operator overloading source:
// https://stackoverflow.com/a/4421719/13279557

class Fixed {
public:
	Fixed();
	Fixed(Fixed const &src);
	Fixed(int const i);
	Fixed(float const f);
	virtual	~Fixed();
	Fixed&	operator=(Fixed const &src);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;

	Fixed&	operator+=(Fixed const &rhs);
	Fixed&	operator-=(Fixed const &rhs);
	Fixed&	operator*=(Fixed const &rhs);
	Fixed&	operator/=(Fixed const &rhs);

	// Prefix increment
	Fixed&	operator++();
	// Postfix increment
	Fixed	operator++(int);

	// Prefix decrement
	Fixed&	operator--();
	// Postfix decrement
	Fixed	operator--(int);

	static Fixed&		min(Fixed &lhs, Fixed &rhs);
	static Fixed const&	min(Fixed const &lhs, Fixed const &rhs);

	static Fixed&		max(Fixed &lhs, Fixed &rhs);
	static Fixed const&	max(Fixed const &lhs, Fixed const &rhs);

private:
	static int const	fractional_bit_count = 8;
	int	raw_bits;
};

std::ostream&	operator<<(std::ostream &out, Fixed const &f);

bool	operator==(Fixed const &lhs, Fixed const &rhs);
bool	operator!=(Fixed const &lhs, Fixed const &rhs);
bool	operator< (Fixed const &lhs, Fixed const &rhs);
bool	operator> (Fixed const &lhs, Fixed const &rhs);
bool	operator<=(Fixed const &lhs, Fixed const &rhs);
bool	operator>=(Fixed const &lhs, Fixed const &rhs);

Fixed	operator+(Fixed lhs, Fixed const &rhs);
Fixed	operator-(Fixed lhs, Fixed const &rhs);
Fixed	operator*(Fixed lhs, Fixed const &rhs);
Fixed	operator/(Fixed lhs, Fixed const &rhs);
