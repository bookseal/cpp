#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this == &copy)
		return (*this);
	AForm::operator=(copy);
	_target = copy._target;
	return (*this);
}

std::string const	&RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try {
		srand(time(NULL));
		AForm::execute(executor);
		std::cout << "* drilling noises *" << std::endl;
		if (rand() % 2)
			std::cout << _target << " has been robotomized successfully" << std::endl;
		else
			std::cout << _target << " robotomization failed" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

// ex03
AForm	*RobotomyRequestForm::create(std::string target)
{
	return (new RobotomyRequestForm(target));
}