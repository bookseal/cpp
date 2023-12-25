#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat staff("staff", 150);
		std::cout << staff << std::endl;
		ShrubberyCreationForm f("form");
		staff.signForm(f);
		staff.executeForm(f);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cin.get();
		Bureaucrat staff("staff", 140);
		std::cout << staff << std::endl;
		ShrubberyCreationForm f("form");
		staff.signForm(f);
		staff.executeForm(f);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cin.get();
		Bureaucrat staff("staff", 130);
		std::cout << staff << std::endl;
		ShrubberyCreationForm f("form");
		staff.signForm(f);
		staff.executeForm(f);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cin.get();
		Bureaucrat staff("staff", 1);
		std::cout << staff << std::endl;
		ShrubberyCreationForm f("form");
		// staff.signForm(f);
		staff.executeForm(f);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cin.get();
		Bureaucrat staff("staff", 1);
		std::cout << staff << std::endl;
		RobotomyRequestForm f("form");
		staff.signForm(f);
		staff.executeForm(f);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cin.get();
		Bureaucrat staff("staff", 1);
		std::cout << staff << std::endl;
		PresidentialPardonForm f("form");
		staff.signForm(f);
		staff.executeForm(f);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}