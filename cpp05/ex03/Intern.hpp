#ifndef INTERN_HPP
#define INTERN_HPP

#include <string.h>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define FORMS 3

class Intern {
	private:
		class FormNotFoundException;
	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();
		Intern &operator=(const Intern &copy);
		AForm *makeForm(std::string form_name, std::string target);
};
#endif