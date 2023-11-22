#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
public:
	Zombie();
	~Zombie();
	std::string getName();
	void setName(const std::string &name);
	void announce(void);
private:
	std::string name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif