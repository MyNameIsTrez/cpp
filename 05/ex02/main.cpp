#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

void	testPresidentialPardonForm()
{
	PresidentialPardonForm f1;

	PresidentialPardonForm f2("f2");

	PresidentialPardonForm f3(f2);

	f1 = f1;

	Bureaucrat b1("b1", 21);
	f2.beSigned(b1);

	f1 = f2;
	assert(f1.getTarget() == "f2");
	assert(f1.getName() == "PresidentialPardonForm");
	assert(f1.getSigned() == true);
	assert(f1.getRequiredSignGrade() == 25);
	assert(f1.getRequiredExecutionGrade() == 5);

	try { f3.execute(b1); assert(false); } catch (AForm::NotSignedException &e) { assert(e.what() == "Form not signed yet"); }

	f3.beSigned(b1);
	try { f3.beSigned(b1); assert(false); } catch (AForm::AlreadySignedException &e) { assert(e.what() == "Form already signed"); }

	try { f3.execute(b1); assert(false); } catch (AForm::GradeTooLowException &e) { assert(e.what() == "Grade too low"); }

	PresidentialPardonForm f5;
	Bureaucrat b3("", 100);
	try { f5.beSigned(b3); assert(false); } catch (AForm::GradeTooLowException &e) { assert(e.what() == "Grade too low"); }

	std::ostringstream ss1;
	ss1 << f1;
	assert(ss1.str() == "Signed form 'PresidentialPardonForm' has a required sign grade of 25 and a required execution grade of 5.");

	std::ostringstream ss2;
	b1.executeForm(f2, ss2);
	assert(ss2.str() == "b1 couldn't execute PresidentialPardonForm because Grade too low.\n");

	PresidentialPardonForm f4;
	Bureaucrat b2("b2", 1);
	f4.beSigned(b2);
	std::ostringstream ss3;
	b2.executeForm(f2, ss3);
	assert(ss3.str() == "f2 has been pardoned by Zaphod Beeblebrox.\nb2 executed PresidentialPardonForm.\n");
}

void	testRobotomyRequestForm()
{
	RobotomyRequestForm f1;

	RobotomyRequestForm f2("f2");

	RobotomyRequestForm f3(f2);

	f1 = f1;

	Bureaucrat b1("b1", 50);
	f2.beSigned(b1);

	f1 = f2;
	assert(f1.getTarget() == "f2");
	assert(f1.getName() == "RobotomyRequestForm");
	assert(f1.getSigned() == true);
	assert(f1.getRequiredSignGrade() == 72);
	assert(f1.getRequiredExecutionGrade() == 45);

	try { f3.execute(b1); assert(false); } catch (AForm::NotSignedException &e) { assert(e.what() == "Form not signed yet"); }

	f3.beSigned(b1);
	try { f3.beSigned(b1); assert(false); } catch (AForm::AlreadySignedException &e) { assert(e.what() == "Form already signed"); }

	try { f3.execute(b1); assert(false); } catch (AForm::GradeTooLowException &e) { assert(e.what() == "Grade too low"); }

	RobotomyRequestForm f5;
	Bureaucrat b3("", 100);
	try { f5.beSigned(b3); assert(false); } catch (AForm::GradeTooLowException &e) { assert(e.what() == "Grade too low"); }

	std::ostringstream ss1;
	ss1 << f1;
	assert(ss1.str() == "Signed form 'RobotomyRequestForm' has a required sign grade of 72 and a required execution grade of 45.");

	std::ostringstream ss2;
	b1.executeForm(f2, ss2);
	assert(ss2.str() == "b1 couldn't execute RobotomyRequestForm because Grade too low.\n");

	RobotomyRequestForm f4;
	Bureaucrat b2("b2", 1);
	f4.beSigned(b2);

	std::ostringstream ss3;
	b2.executeForm(f2, ss3);
	std::string printed = ss3.str();
	assert(printed == "BRRRRRRR!!!\nf2 robotomy succeeded.\nb2 executed RobotomyRequestForm.\n"
	    || printed == "BRRRRRRR!!!\nf2 robotomy failed.\nb2 executed RobotomyRequestForm.\n");

	for (int i = 0; i < 10; i++)
	{
		b2.executeForm(f2, std::cout);
	}
}

void	testShrubberyCreationForm()
{
	ShrubberyCreationForm f1;

	ShrubberyCreationForm f2("f2");

	ShrubberyCreationForm f3(f2);

	f1 = f1;

	Bureaucrat b1("b1", 140);
	f2.beSigned(b1);

	f1 = f2;
	assert(f1.getTarget() == "f2");
	assert(f1.getName() == "ShrubberyCreationForm");
	assert(f1.getSigned() == true);
	assert(f1.getRequiredSignGrade() == 145);
	assert(f1.getRequiredExecutionGrade() == 137);

	try { f3.execute(b1); assert(false); } catch (AForm::NotSignedException &e) { assert(e.what() == "Form not signed yet"); }

	f3.beSigned(b1);
	try { f3.beSigned(b1); assert(false); } catch (AForm::AlreadySignedException &e) { assert(e.what() == "Form already signed"); }

	try { f3.execute(b1); assert(false); } catch (AForm::GradeTooLowException &e) { assert(e.what() == "Grade too low"); }

	ShrubberyCreationForm f5;
	Bureaucrat b3("", 150);
	try { f5.beSigned(b3); assert(false); } catch (AForm::GradeTooLowException &e) { assert(e.what() == "Grade too low"); }

	std::ostringstream ss1;
	ss1 << f1;
	assert(ss1.str() == "Signed form 'ShrubberyCreationForm' has a required sign grade of 145 and a required execution grade of 137.");

	std::ostringstream ss2;
	b1.executeForm(f2, ss2);
	assert(ss2.str() == "b1 couldn't execute ShrubberyCreationForm because Grade too low.\n");

	ShrubberyCreationForm f4;
	Bureaucrat b2("b2", 1);
	f4.beSigned(b2);
	std::ostringstream ss3;
	b2.executeForm(f2, ss3);
	assert(ss3.str() == "b2 executed ShrubberyCreationForm.\n");
	std::ifstream input_file("f2_shrubbery");
	std::stringstream buffer;
	buffer << input_file.rdbuf();
	input_file.close();
	assert(buffer.str() == "v\n|\n");
}

int	main()
{
	srand(time(NULL));

	testPresidentialPardonForm();
	testRobotomyRequestForm();
	testShrubberyCreationForm();

	system("leaks -q execution");

	return EXIT_SUCCESS;
}
