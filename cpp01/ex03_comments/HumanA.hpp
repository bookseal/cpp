#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA {
public:
    // TODO: 클래스르 정의할 때 생성자와 소멸자를 만들어야 한다.
    // TODO: 생성자의 parameter는 뭘지 생각해보자.
	HumanA(std::string inputName, Weapon& inputWeapon);
	~HumanA();
    // TODO: They also have a member function attack() that displays (of course, without the angle brackets)
	void	attack(void);
private:
    // TODO: They both have a Weapon and a name.
	std::string name;
    // Weapon weapon;
    // Weapon *weapon;
    // Weapon &weapon;
    // 위 세 개 중 하나를 골라야 한다.
	Weapon &weapon;
};

#endif