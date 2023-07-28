#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

	const std::string &getTarget() const;

	virtual void execute(const Bureaucrat &executor, std::ostream &ostream = std::cout) const;

	static AForm *create(const std::string &target);

private:
	std::string _target;
};
