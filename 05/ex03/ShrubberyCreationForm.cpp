#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137)
	, _target("Default constructed")
{
	std::cout
		<< "Default constructor of ShrubberyCreationForm called."
		<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137)
	, _target(target)
{
	std::cout
		<< "Constructor of ShrubberyCreationForm called."
		<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src)
{
	std::cout
		<< "Copy constructor of ShrubberyCreationForm called."
		<< std::endl;

	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout
		<< "Destructor of ShrubberyCreationForm called."
		<< std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout
		<< "Copy assignment operator of ShrubberyCreationForm called."
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

const std::string &ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor, std::ostream &ostream) const
{
	(void)ostream;

	checkExecutability(executor.getGrade());

	std::ofstream output_file(_target + "_shrubbery");

	output_file << "v" << std::endl;
	output_file << "|" << std::endl;

	output_file.close();
}

AForm *ShrubberyCreationForm::create(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}
