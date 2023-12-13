#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria
{
	protected:
		std::string _type;
	public:
		Ice();
		Ice(const Ice& copy);
		Ice& operator=(const Ice& op);
		~Ice();
		
		Ice* clone() const;
		void use(ICharacter &target);
};

#endif