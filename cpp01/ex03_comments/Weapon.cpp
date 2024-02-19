#include "Weapon.hpp"

// TODO: A getType() member function that returns a const reference to type.
const std::string &Weapon::getType(){
	return (this->type);
}

// TODO: A setType() member function that sets type using the new one passed as parameter.
void	Weapon::setType(std::string input){
	type = input;
}