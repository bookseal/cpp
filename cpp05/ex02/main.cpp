#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	{
		Bureaucrat staff("staff", 150);
		std::cout << staff << std::endl;
		ShrubberyCreationForm f("form");
		staff.signForm(f);
		staff.executeForm(f);
	}

	{
		std::cin.get();
		Bureaucrat staff("staff", 140);
		std::cout << staff << std::endl;
		ShrubberyCreationForm f("form");
		staff.signForm(f);
		staff.executeForm(f);
	}

	{
		std::cin.get();
		Bureaucrat staff("staff", 130);
		std::cout << staff << std::endl;
		ShrubberyCreationForm f("form");
		staff.signForm(f);
		staff.executeForm(f);
	}

	{
		std::cin.get();
		Bureaucrat staff("staff", 1);
		std::cout << staff << std::endl;
		ShrubberyCreationForm f("form");
		// staff.signForm(f);
		staff.executeForm(f);
	}

	{
		std::cin.get();
		Bureaucrat staff("staff", 1);
		std::cout << staff << std::endl;
		RobotomyRequestForm f("form");
		staff.signForm(f);
		staff.executeForm(f);
	}

	{
		std::cin.get();
		Bureaucrat staff("staff", 1);
		std::cout << staff << std::endl;
		PresidentialPardonForm f("form");
		staff.signForm(f);
		staff.executeForm(f);
	}
	return (0);
}