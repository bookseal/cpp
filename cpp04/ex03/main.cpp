#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iostream>
#include <unistd.h>

void leaks(void)
{
	system("leaks a.out");
}

void print(std::string str)
{
	std::cout << std::endl << std::endl;
	std::cout << "Testing: " << str;
	std::cin.get();
}

int main()
{
	atexit(leaks);

	print("new MaterialSource");
	IMateriaSource *src = new MateriaSource();


	print("MaterialSource::learnMateria()");
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	print("MaterialSource::createMateria()");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	std::cout << std::endl;

	print("Character::equip() ice");
	ICharacter *me = new Character("me");
	me->equip(tmp);

	print("Character::equip() cure");
	tmp = src->createMateria("cure");
	me->equip(tmp);

	print("Character::use()");
	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	print("Character::equip() over and over");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	delete(tmp);

	print("delete");
	delete bob;
	delete me;
	delete src;
	
	return 0;
}