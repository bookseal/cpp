#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
	public: 
		AMateria();
		AMateria(std::string const &type);
		AMateria(const AMateria& copy);
		AMateria& operator=(const AMateria& op);
		virtual ~AMateria();
		
		std::string const &getType() const;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
};

#endif