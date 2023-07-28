#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

	const std::string &getTarget() const;

	virtual void execute(const Bureaucrat &executor, std::ostream &ostream = std::cout) const;

	static AForm *create(const std::string &target);

private:
	std::string _target;
};
