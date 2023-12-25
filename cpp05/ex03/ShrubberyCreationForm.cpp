#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this == &copy)
		return (*this);
	AForm::operator=(copy);
	_target = copy._target;
	return (*this);
}

std::string const	&ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

class ShrubberyCreationForm::FileOpenException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("File open failed");
		}
};

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::ofstream file;
	file.open((_target + "_shrubbery").c_str());
	if (!file.is_open())
		throw ShrubberyCreationForm::FileOpenException();
	file << "       _-_" << std::endl;
	file << "    /~~   ~~\\" << std::endl;
	file << " /~~         ~~\\" << std::endl;
	file << "{               }" << std::endl;
	file << " \\  _-     -_  /" << std::endl;
	file << "   ~  \\\\ //  ~" << std::endl;
	file << "_- -   | | _- _" << std::endl;
	file << "  _ -  | |   -_" << std::endl;
	file << "      // \\\\" << std::endl;
	file.close();
}

// ex03
AForm	*ShrubberyCreationForm::create(std::string target)
{
	return (new ShrubberyCreationForm(target));
}