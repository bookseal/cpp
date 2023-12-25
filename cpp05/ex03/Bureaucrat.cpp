#include "Bureaucrat.hpp"

class Bureaucrat::GradeTooHighException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Grade too high");
		}
};

class Bureaucrat::GradeTooLowException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Grade too low");
		}
};

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	try {
		checkGrade(grade);
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
		_grade = 1;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
		_grade = 150;
	}
}


Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this == &copy)
		return (*this);
	_grade = copy._grade;
	return (*this);
}

void Bureaucrat::checkGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const std::string &Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	try {
		checkGrade(_grade - 1);
		_grade--;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade()
{
	try {
		checkGrade(_grade + 1);
		_grade++;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}

// ex03
class Bureaucrat::NotFoundException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Form not found");
		}
};

void Bureaucrat::signForm(AForm &form)
{
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	// ex03
	catch (Bureaucrat::NotFoundException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << "." << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	// ex03
	catch (Bureaucrat::NotFoundException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << "." << std::endl;
	}
}