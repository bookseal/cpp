#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA {
public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA();
	void	attack(void);
private:
    // TODO: They both have a Weapon and a name.
	std::string name;
    // Weapon weapon;
    // Weapon *weapon;
    // Weapon &weapon;
    // 고민해야돼. 차이점을 알고
	Weapon &weapon;
};

#endif