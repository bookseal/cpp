#ifndef AAnimal_HPP
# define AAnimal_HPP

#include <iostream>
#include <string>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(const AAnimal& copy);
		AAnimal& operator=(const AAnimal& op);
		virtual ~AAnimal();
		virtual void makeSound() const = 0;
		virtual std::string getType() const = 0;
	
	protected:
		std::string type;
};

#endif