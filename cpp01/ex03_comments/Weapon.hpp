#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>
class Weapon {
private:
	std::string type;

public:
    Weapon();
    Weapon(std::string input);
    // TODO: A getType() member function that returns a const reference to type.
    const std::string &getType();
    // TODO: A setType() member function that sets type using the new one passed as parameter.
	void	setType(std::string input);
};

#endif