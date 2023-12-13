#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		Dog(const Dog& copy);
		~Dog();
		Dog& operator=(const Dog& op);
		void makeSound() const;
		std::string getIdeaFromBrain(int i) const;
	
	private:
		Brain* brain;
};

#endif