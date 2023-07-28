#pragma once

#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat &src);
	virtual ~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &src);

	const std::string &getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void signForm(AForm &form, std::ostream &ostream = std::cout) const;

	void executeForm(const AForm &form, std::ostream &ostream = std::cout) const;

	struct GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};

	struct GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};

private:
	const std::string _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat);
