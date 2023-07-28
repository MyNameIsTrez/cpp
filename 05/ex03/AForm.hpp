#pragma once

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
public:
	AForm();
	AForm(const std::string &name, int required_sign_grade, int required_execution_grade);
	AForm(const AForm &src);
	virtual ~AForm();
	AForm &operator=(const AForm &src);

	const std::string &getName() const;
	bool getSigned() const;
	int getRequiredSignGrade() const;
	int getRequiredExecutionGrade() const;

	virtual const std::string &getTarget() const = 0;

	void beSigned(const Bureaucrat &bureaucrat);

	virtual void execute(const Bureaucrat &executor, std::ostream &ostream = std::cout) const = 0;

	void checkExecutability(int grade) const;

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

	struct NotSignedException : public std::exception
	{
		const char *what() const throw();
	};

private:
	const std::string _name;
	bool _signed;
	const int _required_sign_grade;
	const int _required_execution_grade;
};

std::ostream &operator<<(std::ostream &ostream, const AForm &form);
