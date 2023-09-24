#include "Weapon.cpp"

class HumanA {
public:
	HumanA();
	~HumanA();
	void	attack(void);
private:
	Weapon weapon;
	std::string name;
}