#ifndef SHUBBERYCREATIONFORM_HPP
#define SHUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string		_target;
		class			FileOpenException;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

		std::string const	&getTarget() const;
		void				execute(Bureaucrat const &executor) const;

		// ex03
		static AForm		*create(std::string target);
};

#endif