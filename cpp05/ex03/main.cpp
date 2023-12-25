#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	try
	{
		Bureaucrat	staff("staff", 42);
		Intern	someRandomIntern;
		AForm*	rrf;

		rrf = someRandomIntern.makeForm("unknown", "Bender");
		staff.signForm(*rrf);
		staff.executeForm(*rrf);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cin.get();
		Bureaucrat	staff("staff", 42);
		Intern	someRandomIntern;
		AForm*	rrf;

		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		// staff.signForm(*rrf);
		staff.executeForm(*rrf);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cin.get();
		Bureaucrat	staff("staff", 42);
		Intern	someRandomIntern;
		AForm*	rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		staff.signForm(*rrf);
		staff.executeForm(*rrf);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cin.get();
		Bureaucrat	staff("staff", 1);
		Intern	someRandomIntern;
		AForm*	rrf;

		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		staff.signForm(*rrf);
		staff.executeForm(*rrf);
	}
		catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}