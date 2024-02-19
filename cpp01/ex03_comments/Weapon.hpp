#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
	std::string type;

public:
    // TODO: A getType() member function that returns a const reference to type.
    const std::string &getType();
    // TODO: A setType() member function that sets type using the new one passed as parameter.
	void	setType(std::string input);
};

#endif