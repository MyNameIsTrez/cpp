#pragma once

#include <ostream>
#include <string>

class Bureaucrat;

class Form
{
public:
	Form();
	Form(const std::string &name, int required_sign_grade, int required_execution_grade);
	Form(const Form &src);
	virtual ~Form();
	Form &operator=(const Form &src);

	const std::string &getName() const;
	bool getSigned() const;
	int getRequiredSignGrade() const;
	int getRequiredExecutionGrade() const;

	void beSigned(const Bureaucrat &bureaucrat);

	struct GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};

	struct GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};

	struct AlreadySignedException : public std::exception
	{
		const char *what() const throw();
	};

private:
	const std::string _name;
	bool _signed;
	const int _required_sign_grade;
	const int _required_execution_grade;
};

std::ostream &operator<<(std::ostream &ostream, const Form &form);
