#include "HumanA.hpp"

// TODO: 콜론 뒤의 weapon(inputWeapon)은 무엇을 의미하는가?
// TODO: While HumanA takes the Weapon in its constructor, HumanB doesn’t.
HumanA::HumanA(std::string inputName, Weapon& inputWeapon) {
    name = inputName;
    weapon = inputWeapon;
}

HumanA::~HumanA() {
}

// TODO: They also have a member function attack() that displays (of course, without the angle brackets)
void HumanA::attack(void) {
    // TODO: weapon.type이 안 되는 이유를 생각해보자.
    // std::cout << name << " attacks with their " << weapon.type << std::endl;
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
