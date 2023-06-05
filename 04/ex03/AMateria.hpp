#pragma once

#include <string>

class ICharacter;

class AMateria
{
public:
	AMateria(std::string const &type);
	AMateria &operator=(const AMateria &src);
	virtual ~AMateria();

	std::string const &getType() const;

	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);

protected:
	AMateria(const AMateria &src);

	std::string _type;

private:
	AMateria();
};
