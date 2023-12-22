#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string		_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);

		std::string const	&getTarget() const;
		void				execute(Bureaucrat const &executor) const;
};

#endif