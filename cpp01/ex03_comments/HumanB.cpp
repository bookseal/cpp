#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    // TODO: HumanB may not always have a Weapon, whereas HumanA will always be armed.
	this->name = name;
    // NULL은 아무것도 가리키지 않는 상태를 의미한다.
    // 참조자는 NULL을 가리킬 수 없다.
	this->weapon = NULL;
}

HumanB::~HumanB(){
}

void HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}

void HumanB::attack(void) {
	if (this->weapon == NULL)
		std::cout << this->name << " has no weapon" << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
