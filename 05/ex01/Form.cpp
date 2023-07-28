#include "Form.hpp"

#include "Bureaucrat.hpp"

#include <iostream>

Form::Form()
	: _name("Default constructed")
	, _signed(false)
	, _required_sign_grade(150)
	, _required_execution_grade(150)
{
	std::cout
		<< "Default constructor of Form called."
		<< std::endl;
}

Form::Form(const std::string &name, int required_sign_grade, int required_execution_grade)
	: _name(name)
	, _signed(false)
	, _required_sign_grade(required_sign_grade)
	, _required_execution_grade(required_execution_grade)
{
	std::cout
		<< "Constructor of Form called."
		<< std::endl;

	if (required_sign_grade < 1 || required_execution_grade < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (required_sign_grade > 150 || required_execution_grade > 150)
	{
		throw Form::GradeTooLowException();
	}
}

Form::Form(const Form &src)
	: _name(src._name)
	, _required_sign_grade(src._required_sign_grade)
	, _required_execution_grade(src._required_execution_grade)
{
	std::cout
		<< "Copy constructor of Form called."
		<< std::endl;

	*this = src;
}

Form::~Form()
{
	std::cout
		<< "Destructor of Form called."
		<< std::endl;
}

Form &Form::operator=(const Form &src)
{
	std::cout
		<< "Copy assignment operator of Form called."
		<< std::endl;

	if (this == &src)
	{
		return (*this);
	}

	_signed = src._signed;

	return (*this);
}

const std::string &Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getRequiredSignGrade() const
{
	return _required_sign_grade;
}

int Form::getRequiredExecutionGrade() const
{
	return _required_execution_grade;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _required_sign_grade)
	{
		throw Form::GradeTooLowException();
	}

	if (_signed)
	{
		throw Form::AlreadySignedException();
	}

	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *Form::AlreadySignedException::what() const throw()
{
	return "Form already signed";
}

std::ostream &operator<<(std::ostream &ostream, const Form &form)
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
