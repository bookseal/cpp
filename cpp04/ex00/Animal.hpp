#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	public:
		Animal();
		Animal(const Animal& copy);
		// ~Animal();
		virtual ~Animal();
		Animal& operator=(const Animal& op);
		virtual void makeSound() const;
		std::string getType() const;
		void setType(std::string type);
	
	protected:
		std::string type;
};

#endif