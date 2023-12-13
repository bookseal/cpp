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
		std::string getType() const;
	
	protected:
		std::string type;
};

#endif