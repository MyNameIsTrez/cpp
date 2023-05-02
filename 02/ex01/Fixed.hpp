#pragma once

#include <iostream>

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

private:
	static int const	fractional_bit_count = 8;
	int	raw_bits;
};

std::ostream&	operator<<(std::ostream &out, Fixed const &f);
