#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {	
	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;
		class 				GradeTooHighException;
		class				GradeTooLowException;
	
	public:
		Form();
		Form(const Form &copy);
		~Form();
		Form &operator=(const Form &copy);

		Form(std::string name, int gradeToSign, int gradeToExecute);
		void				checkGrade(int grade);
		std::string const	&getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void				beSigned(Bureaucrat &bureaucrat);
};

std::ostream	&operator<<(std::ostream &out, const Form &form);

#endif