#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &copy)
{
	(void)copy;
	return (*this);
}

class Intern::FormNotFoundException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Form not found");
		}
};

AForm *Intern::makeForm(std::string form_name, std::string target)
{
	AForm	*form;
	std::string form_names[FORMS] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm	*(*form_creators[FORMS])(std::string target) = {
		ShrubberyCreationForm::create,
		RobotomyRequestForm::create,
		PresidentialPardonForm::create
	};
	
	for (int i = 0; i < FORMS; i++)
	{
		if (form_name == form_names[i])
		{
			form = form_creators[i](target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
	}
	throw Intern::FormNotFoundException();
	return (NULL);
}
