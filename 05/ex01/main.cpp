#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>
#include <sstream>

void	test()
{
	Form f1;

	Form f2("f2", 1, 1);
	Form f3("", 150, 1);
	Form f4("", 1, 150);
	Form f5("", 150, 150);

	Form f6(f1);

	f1 = f1;

	f1 = f2;
	assert(f1.getName() == "Default constructed");
	assert(f1.getSigned() == false);
	assert(f1.getRequiredSignGrade() == 150);
	assert(f1.getRequiredExecutionGrade() == 150);

	try { Form f7("", 0, 42); assert(false); } catch (Form::GradeTooHighException &e) { assert(e.what() == "Grade too high"); }
	try { Form f7("", 42, 0); assert(false); } catch (Form::GradeTooHighException &e) { assert(e.what() == "Grade too high"); }
	try { Form f8("", 151, 42); assert(false); } catch (Form::GradeTooLowException &e) { assert(e.what() == "Grade too low"); }
	try { Form f8("", 42, 151); assert(false); } catch (Form::GradeTooLowException &e) { assert(e.what() == "Grade too low"); }

	std::ostringstream ss1;
	ss1 << f1;
	assert(ss1.str() == "Unsigned form 'Default constructed' has a required sign grade of 150 and a required execution grade of 150.");

	Bureaucrat b1;
	std::ostringstream ss1;
	b1.signForm(f1, ss1);
	assert(ss1.str() == "Default constructed signed Default constructed.\n");

	std::ostringstream ss2;
	b1.signForm(f1, ss2);
	assert(ss2.str() == "Default constructed couldn't sign Default constructed because Form already signed.\n");

	std::ostringstream ss3;
	b1.signForm(f2, ss3);
	assert(ss3.str() == "Default constructed couldn't sign f2 because Grade too low.\n");
}

int	main()
{
	test();

	system("leaks -q form");

	return EXIT_SUCCESS;
}
