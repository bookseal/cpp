#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		class				GradeTooHighException;
		class				GradeTooLowException;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &copy);

		void				checkGrade(int grade);
		const std::string	&getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();

		void 				signForm(class AForm &Aform);

		// ex02
		void				executeForm(AForm const &Aform);
};

std::ostream		&operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
#endif