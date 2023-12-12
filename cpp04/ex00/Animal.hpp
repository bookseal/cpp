#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	public:
		Animal();
		Animal(const Animal& copy);
		~Animal();
		Animal& operator=(const Animal& op);
		void makeSound() const;
		std::string getType() const;
		void setType(std::string type);
	
	public:
		std::string type;
};

#endif