#include "Zombie.hpp"

Zombie::Zombie() {};
Zombie::~Zombie() {
	std::cout << getName() << ": Destroyed." << std::endl;
};
std::string Zombie::getName(){ return name; };
void Zombie::setName(const std::string &str){ name = str; };
void Zombie::announce(void){
	std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
};