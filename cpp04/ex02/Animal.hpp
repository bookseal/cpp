#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	public:
		Animal();
		Animal(const Animal& copy);
		virtual ~Animal();
		Animal& operator=(const Animal& op);
		virtual void makeSound() const = 0;
		virtual std::string getType() const;
		virtual void setType(std::string type);
	
	protected:
		std::string type;
};

#endif