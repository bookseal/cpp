#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class Amateria;

class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& copy);
		~MateriaSource();
		MateriaSource& operator=(const MateriaSource& op);
		
		void learnMateria(AMateria *m);
		AMateria *createMateria(std::string const &type);
	
	private:
		AMateria* materia[4];
		int count;
};
#endif