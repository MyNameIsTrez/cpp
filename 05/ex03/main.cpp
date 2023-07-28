#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

void	test()
{
	Bureaucrat b1("b1", 1);


	Intern i1;

	assert(i1.makeForm("", "") == NULL);

	AForm *f;
	f = i1.makeForm("presidential pardon form", "a");
	assert(f->getName() == "PresidentialPardonForm");
	assert(f->getTarget() == "a");

	b1.signForm(*f);
	assert(f->getSigned() == true);

	std::ostringstream ss1;
	b1.executeForm(*f, ss1);
	assert(ss1.str() == "a has been pardoned by Zaphod Beeblebrox.\nb1 executed PresidentialPardonForm.\n");

	delete f;


	f = i1.makeForm("robotomy request form", "b");
	assert(f->getName() == "RobotomyRequestForm");
	assert(f->getTarget() == "b");

	b1.signForm(*f);
	assert(f->getSigned() == true);

	std::ostringstream ss2;
	b1.executeForm(*f, ss2);
	assert(ss2.str() == "BRRRRRRR!!!\nb robotomy succeeded.\nb1 executed RobotomyRequestForm.\n"
	    || ss2.str() == "BRRRRRRR!!!\nb robotomy failed.\nb1 executed RobotomyRequestForm.\n");

	delete f;


	f = i1.makeForm("shrubbery creation form", "c");
	assert(f->getName() == "ShrubberyCreationForm");
	assert(f->getTarget() == "c");

	b1.signForm(*f);
	assert(f->getSigned() == true);

	std::ostringstream ss3;
	b1.executeForm(*f, ss3);
	assert(ss3.str() == "b1 executed ShrubberyCreationForm.\n");

	std::ifstream input_file("c_shrubbery");
	std::stringstream buffer;
	buffer << input_file.rdbuf();
	input_file.close();
	assert(buffer.str() == "v\n|\n");

	delete f;
}

int	main()
{
	test();

	system("leaks -q intern");

	return EXIT_SUCCESS;
}
