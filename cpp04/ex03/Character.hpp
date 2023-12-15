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
		int count;
		AMateria* inventory[4];
		AMateria* on_the_floor[100];
		int on_the_floor_count;

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

		void deep_inventory_copy(const Character& from, Character* to);
		void deep_on_the_floor_copy(const Character& from, Character* to);
};

#endif