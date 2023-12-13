#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include <string>
#define MAX_MATERIA 4

class AMateria;

class Character: public ICharacter
{
	private:
		std::string name;
		AMateria* inventory[4];
		int count;
	public:
		Character();
		Character(std::string name);
		Character(const Character& copy);
		~Character();
		Character& operator=(const Character& op);

		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);	
};

#endif