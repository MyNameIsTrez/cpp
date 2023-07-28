#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

Intern::Intern()
{
	std::cout
		<< "Default constructor of Intern called."
		<< std::endl;
}

Intern::~Intern()
{
	std::cout
		<< "Destructor of Intern called."
		<< std::endl;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &formTarget) const
{
	const t_constructorFn constructorFns[] = {
		{"presidential pardon form", PresidentialPardonForm::create},
		{"robotomy request form", RobotomyRequestForm::create},
		{"shrubbery creation form", ShrubberyCreationForm::create},
	};

	AForm *form = NULL;

	for (size_t i = 0; i < sizeof(constructorFns) / sizeof(*constructorFns); i++)
	{
		if (constructorFns[i].className == formName)
		{
			form = constructorFns[i].creationFn(formTarget);
			break;
		}
	}

	if (form)
	{
		std::cout
			<< "Intern created the form '"
			<< formName
			<< "'."
			<< std::endl;
	}
	else
	{
		std::cout
			<< "Intern wasn't able to create the form '"
			<< formName
			<< "', since that form doesn't exist."
			<< std::endl;
	}

	return form;
}
