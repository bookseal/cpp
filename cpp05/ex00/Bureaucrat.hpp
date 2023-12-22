// A Bureaucrat must have:
// • A constant name.
// • And a grade that ranges from 1 (highest possible grade) to 150 (lowest possible
// grade).
// Any attempt to instantiate a Bureaucrat using an invalid grade must throw an ex- ception:
// either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.
// You will provide getters for both these attributes: getName() and getGrade(). Im- plement also two member functions to increment or decrement the bureaucrat grade. If the grade is out of range, both of them will throw the same exceptions as the constructor.
// Remember.  Since grade 1 is the highest one and 150 the lowest,
// incrementing a grade 3 should give a grade 2 to the bureaucrat
// The thrown exceptions must be catchable using try and catch blocks:
// You will implement an overload of the insertion («) operator to print something like (without the angle brackets):
// <name>, bureaucrat grade <grade>.
// As usual, turn in some tests to prove everything works as expected.

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		class GradeTooHighException;
		class GradeTooLowException;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &copy);

		const std::string	&getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		std::of
}

#endif