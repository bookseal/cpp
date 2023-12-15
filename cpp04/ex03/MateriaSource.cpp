#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "🧪MateriaSource default constructor called" << std::endl;
	this->count = 0;
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	std::cout << "🧪MateriaSource copy constructor called" << std::endl;
	*this = copy;
}

MateriaSource::~MateriaSource()
{
	std::cout << "🧪MateriaSource destructor called" << std::endl;
	for (int i = 0; i < this->count; i++)
		delete this->materia[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& op)
{
	std::cout << "🧪MateriaSource assignation operator called" << std::endl;
	if (this == &op)
		return (*this);
	for (int i = 0; i < this->count; i++)
		delete this->materia[i];
	this->count = op.count;
	for (int i = 0; i < this->count; i++)
		this->materia[i] = op.materia[i]->clone();
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (this->count == 4 || m == NULL)
		return ;
	this->materia[this->count] = m;
	this->count++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->count; i++)
		if (this->materia[i]->getType() == type)
		{
			std::cout << "🧪MateriaSource 🎨create Materia" << std::endl;
			return (this->materia[i]->clone());
		}
	return (NULL);
}