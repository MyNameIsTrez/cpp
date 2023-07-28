#include "Bureaucrat.hpp"

#include "Form.hpp"

#include <iostream>

Bureaucrat::Bureaucrat()
	: _name("Default constructed")
	, _grade(150)
{
	std::cout
		<< "Default constructor of Bureaucrat called."
		<< std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
	: _name(name)
	, _grade(grade)
{
	std::cout
		<< "Constructor of Bureaucrat called."
		<< std::endl;

	if (_grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (_grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	std::cout
		<< "Copy constructor of Bureaucrat called."
		<< std::endl;

	*this = src;
}

Bureaucrat::~Bureaucrat()
{
	std::cout
		<< "Destructor of Bureaucrat called."
		<< std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout
		<< "Copy assignment operator of Bureaucrat called."
		<< std::endl;

	if (this == &src)
	{
		return (*this);
	}

	_grade = src._grade;

	return (*this);
}

const std::string &Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	_grade++;
}

void Bureaucrat::signForm(Form &form, std::ostream &ostream = std::cout) const
{
	try
	{
		form.beSigned(*this);
		ostream
			<< _name
			<< " signed "
			<< form.getName()
			<< "."
			<< std::endl;
	}
	catch (std::exception &e)
	{
		ostream
			<< _name
			<< " couldn't sign "
			<< form.getName()
			<< " because "
			<< e.what()
			<< "."
			<< std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat)
{
	return ostream
		<< "Bureaucrat '"
		<< bureaucrat.getName()
		<< "' has a grade of "
		<< bureaucrat.getGrade()
		<< ".";
}
