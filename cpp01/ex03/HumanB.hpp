#include "Weapon.cpp"

class HumanB {
public:
	HumanB();
	~HumanB();
	void	attack(void);
private:
	Weapon weapon;
	std::string name;
}