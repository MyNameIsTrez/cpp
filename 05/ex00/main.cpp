#include "Bureaucrat.hpp"

#include <iostream>
#include <sstream>

void	test()
{
	Bureaucrat b1;

	Bureaucrat b2("", 1);
	Bureaucrat b3("", 150);

	Bureaucrat b4(b1);

	b1 = b1;

	b1 = b2;
	assert(b1.getName() == "Default constructed");
	assert(b1.getGrade() == 1);

	try { Bureaucrat b5("", 0); assert(false); } catch (Bureaucrat::GradeTooHighException &e) { assert(e.what() == "Grade too high"); }
	try { Bureaucrat b6("", 151); assert(false); } catch (Bureaucrat::GradeTooLowException &e) { assert(e.what() == "Grade too low"); }

	try { b2.incrementGrade(); assert(false); } catch (Bureaucrat::GradeTooHighException &e) {}
	try { b3.decrementGrade(); assert(false); } catch (Bureaucrat::GradeTooLowException &e) {}

	b2.decrementGrade();
	assert(b2.getGrade() == 2);

	b3.incrementGrade();
	assert(b3.getGrade() == 149);

	std::ostringstream ss;
	ss << b1;
	assert(ss.str() == "Bureaucrat 'Default constructed' has a grade of 1.");
}

int	main()
{
	test();

	system("leaks -q bureaucrat");

	return EXIT_SUCCESS;
}
