#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	{
		Bureaucrat	staff("staff", 42);
		Intern	someRandomIntern;
		AForm*	rrf;

		rrf = someRandomIntern.makeForm("unknown", "Bender");
		if (rrf)
		{
			staff.signForm(*rrf);
			staff.executeForm(*rrf);
		}
	}

	{
		std::cin.get();
		Bureaucrat	staff("staff", 42);
		Intern	someRandomIntern;
		AForm*	rrf;

		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		if (rrf)
		{
			// staff.signForm(*rrf);
			staff.executeForm(*rrf);
		}
	}

	{
		std::cin.get();
		Bureaucrat	staff("staff", 42);
		Intern	someRandomIntern;
		AForm*	rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			staff.signForm(*rrf);
			staff.executeForm(*rrf);
		}
	}

	{
		std::cin.get();
		Bureaucrat	staff("staff", 1);
		Intern	someRandomIntern;
		AForm*	rrf;

		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		if (rrf)
		{
			staff.signForm(*rrf);
			staff.executeForm(*rrf);
		}
	}
	return (0);
}