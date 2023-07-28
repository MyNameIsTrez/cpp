#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

	const std::string &getTarget() const;

	virtual void execute(const Bureaucrat &executor, std::ostream &ostream = std::cout) const;

	static AForm *create(const std::string &target);

private:
	std::string _target;
};
