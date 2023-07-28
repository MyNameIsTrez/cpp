#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45)
	, _target("Default constructed")
{
	std::cout
		<< "Default constructor of RobotomyRequestForm called."
		<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45)
	, _target(target)
{
	std::cout
		<< "Constructor of RobotomyRequestForm called."
		<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm(src)
{
	std::cout
		<< "Copy constructor of RobotomyRequestForm called."
		<< std::endl;

	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout
		<< "Destructor of RobotomyRequestForm called."
		<< std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout
		<< "Copy assignment operator of RobotomyRequestForm called."
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

const std::string &RobotomyRequestForm::getTarget() const
{
	return _target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor, std::ostream &ostream) const
{
	checkExecutability(executor.getGrade());

	ostream
		<< "BRRRRRRR!!!"
		<< std::endl;

	if (rand() % 2 == 0)
	{
		ostream
			<< _target
			<< " robotomy succeeded."
			<< std::endl;
	}
	else
	{
		ostream
			<< _target
			<< " robotomy failed."
			<< std::endl;
	}
}

AForm *RobotomyRequestForm::create(const std::string &target)
{
	return new RobotomyRequestForm(target);
}
