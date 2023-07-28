#pragma once

#include <string>

class AForm;

class Intern
{
public:
	Intern();
	virtual ~Intern();

	AForm *makeForm(const std::string &formName, const std::string &formTarget) const;

private:
	Intern(const Intern &src);
	Intern &operator=(const Intern &src);

	size_t getFormIndex(const std::string &formName) const;

	struct t_constructorFn {
		std::string	className;
		AForm		*(*creationFn)(const std::string &target);
	};
};
