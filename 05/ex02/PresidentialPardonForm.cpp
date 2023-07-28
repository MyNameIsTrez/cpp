#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5)
	, _target("Default constructed")
{
	std::cout
		<< "Default constructor of PresidentialPardonForm called."
		<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5)
	, _target(target)
{
	std::cout
		<< "Constructor of PresidentialPardonForm called."
		<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	: AForm(src)
{
	std::cout
		<< "Copy constructor of PresidentialPardonForm called."
		<< std::endl;

	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout
		<< "Destructor of PresidentialPardonForm called."
		<< std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	std::cout
		<< "Copy assignment operator of PresidentialPardonForm called."
		<< std::endl;

	if (this == &src)
	{
		AForm::operator=(src);
		return (*this);
	}

	AForm::operator=(src);
	_target = src._target;

	return (*this);
}

const std::string &PresidentialPardonForm::getTarget() const
{
	return _target;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor, std::ostream &ostream) const
{
	checkExecutability(executor.getGrade());

	ostream
		<< _target
		<< " has been pardoned by Zaphod Beeblebrox."
		<< std::endl;
}
