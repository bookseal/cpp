#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(){
	{
		Weapon  club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}

//	std::cout << std::endl;
//
//	{
//		Weapon  club = Weapon("crude spiked club");
//		HumanB jim("Jim");
//		jim.setWeapon(club);
//		jim.attack();
//		club.setType("some other type of club");
//		jim.attack();
//	}
//
//	std::cout << std::endl;
//
//	{
//		Weapon  club = Weapon("crude spiked club");
//		HumanB jesus("Jusus");
//		// jesus.setWeapon(club);
//		jesus.attack();
//		club.setType("some other type of club");
//		jesus.attack();
//	}
	return 0;
}