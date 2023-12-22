#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

class Form::GradeTooHighException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Grade too high");
		}
};

class Form::GradeTooLowException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Grade too low");
		}
};

void Form::checkGrade(int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) 
	: _name(name)
	, _signed(false)
	, _gradeToSign(gradeToSign)
	, _gradeToExecute(gradeToExecute)
{
	try {
		checkGrade(gradeToSign);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		checkGrade(gradeToExecute);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

Form::Form(const Form &copy) 
	: _name(copy._name)
	, _signed(copy._signed)
	, _gradeToSign(copy._gradeToSign)
	, _gradeToExecute(copy._gradeToExecute)
{
}

Form::~Form()
{
}

Form &Form::operator=(const Form &copy)
{
	if (this == &copy)
		return (*this);
	_signed = copy._signed;
	return (*this);
}

std::string const	&Form::getName() const
{
	return (_name);
}

bool				Form::getSigned() const
{
	return (_signed);
}

int					Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int					Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void				Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.getName() << " is ";
	if (form.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute";
	return (out);
}