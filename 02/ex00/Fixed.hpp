#pragma once

class Fixed {
public:
	Fixed();
	Fixed(Fixed const &src);
	virtual	~Fixed();
	Fixed&	operator=(Fixed const &src);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	static int const	fractional_bit_count = 8;
	int	raw_bits;
};
