#include "Weapon.hpp"

Weapon::Weapon() {
    std::cout << "Default Constructor" << std::endl;
}

Weapon::Weapon(std::string input)
{
    std::cout << "Parameterized Constructor" << std::endl;
    type = input;
}

// TODO: A getType() member function that returns a const reference to type.
const std::string &Weapon::getType(){
	return (this->type);
}

// TODO: A setType() member function that sets type using the new one passed as parameter.
void	Weapon::setType(std::string input){
	type = input;
}