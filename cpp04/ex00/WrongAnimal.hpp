#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& copy);
		virtual ~WrongAnimal();
		// ~WrongAnimal();
		WrongAnimal& operator=(const WrongAnimal& op);
		// virtual void makeSound() const;
		void makeSound() const;
		std::string getType() const;
		void setType(std::string type);
	
	protected:
		std::string type;
};

#endif