#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;
		class 				GradeTooHighException;
		class				GradeTooLowException;
		// ex02
		class				NotSignedException;
	
	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &copy);
		virtual ~AForm();
		AForm &operator=(const AForm &copy);

		void				checkGrade(int grade);

		std::string const	&getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		// ex01
		void				beSigned(Bureaucrat &bureaucrat);
		// ex02
		virtual	void		execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<<(std::ostream &out, const AForm &form);
#endif