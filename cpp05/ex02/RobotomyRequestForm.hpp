#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"

class RobotomyrequestForm : public AForm
{
	private:
		std::string		_target;
	public:
		RobotomyrequestForm();
		RobotomyrequestForm(std::string target);
		RobotomyrequestForm(const RobotomyrequestForm &copy);
		~RobotomyrequestForm();
		RobotomyrequestForm &operator=(const RobotomyrequestForm &copy);

		std::string const	&getTarget() const;
		void				execute(Bureaucrat const &executor) const;
};

#endif