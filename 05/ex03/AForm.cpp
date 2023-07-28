#include "AForm.hpp"

#include "Bureaucrat.hpp"

#include <iostream>

AForm::AForm()
	: _name("Default constructed")
	, _signed(false)
	, _required_sign_grade(150)
	, _required_execution_grade(150)
{
	std::cout
		<< "Default constructor of AForm called."
		<< std::endl;
}

AForm::AForm(const std::string &name, int required_sign_grade, int required_execution_grade)
	: _name(name)
	, _signed(false)
	, _required_sign_grade(required_sign_grade)
	, _required_execution_grade(required_execution_grade)
{
	std::cout
		<< "Constructor of AForm called."
		<< std::endl;

	if (required_sign_grade < 1 || required_execution_grade < 1)
	{
		throw AForm::GradeTooHighException();
	}
	else if (required_sign_grade > 150 || required_execution_grade > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

AForm::AForm(const AForm &src)
	: _name(src._name)
	, _required_sign_grade(src._required_sign_grade)
	, _required_execution_grade(src._required_execution_grade)
{
	std::cout
		<< "Copy constructor of AForm called."
		<< std::endl;

	*this = src;
}

AForm::~AForm()
{
	std::cout
		<< "Destructor of AForm called."
		<< std::endl;
}

AForm &AForm::operator=(const AForm &src)
{
	std::cout
		<< "Copy assignment operator of AForm called."
		<< std::endl;

	if (this == &src)
	{
		return (*this);
	}

	_signed = src._signed;

	return (*this);
}

const std::string &AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getRequiredSignGrade() const
{
	return _required_sign_grade;
}

int AForm::getRequiredExecutionGrade() const
{
	return _required_execution_grade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _required_sign_grade)
	{
		throw AForm::GradeTooLowException();
	}

	if (_signed)
	{
		throw AForm::AlreadySignedException();
	}

	_signed = true;
}

void AForm::checkExecutability(int grade) const
{
	if (!_signed)
	{
		throw AForm::NotSignedException();
	}

	if (grade > _required_execution_grade)
	{
		throw AForm::GradeTooLowException();
	}
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return "Form already signed";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "Form not signed yet";
}

std::ostream &operator<<(std::ostream &ostream, const AForm &form)
{
	return ostream
		<< (form.getSigned() ? "Signed" : "Unsigned")
		<< " form '"
		<< form.getName()
		<< "' has a required sign grade of "
		<< form.getRequiredSignGrade()
		<< " and a required execution grade of "
		<< form.getRequiredExecutionGrade()
		<< ".";
}
