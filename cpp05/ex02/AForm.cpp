#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

class AForm::GradeTooHighException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Grade too high");
		}
};

class AForm::GradeTooLowException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Grade too low");
		}
};

void AForm::checkGrade(int grade)
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	else if (grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) 
	: _name(name)
	, _signed(false)
	, _gradeToSign(gradeToSign)
	, _gradeToExecute(gradeToExecute)
{
	checkGrade(gradeToSign);
	checkGrade(gradeToExecute);
}

AForm::AForm(const AForm &copy) 
	: _name(copy._name)
	, _signed(copy._signed)
	, _gradeToSign(copy._gradeToSign)
	, _gradeToExecute(copy._gradeToExecute)
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &copy)
{
	if (this == &copy)
		return (*this);
	_signed = copy._signed;
	return (*this);
}

std::string const	&AForm::getName() const
{
	return (_name);
}

bool				AForm::getSigned() const
{
	return (_signed);
}

int					AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int					AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

// ex01
void				AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

std::ostream	&operator<<(std::ostream &out, const AForm &Aform)
{
	out << "AForm " << Aform.getName() << " is ";
	if (Aform.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << Aform.getGradeToSign() << " to sign and grade " << Aform.getGradeToExecute() << " to execute";
	return (out);
}

// ex02
class AForm::NotSignedException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Form not signed");
		}
};

// ex02
void	AForm::execute(Bureaucrat const &executor) const
{
	if (!_signed)
		throw AForm::NotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
}