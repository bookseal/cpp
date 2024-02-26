#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(){
	{
        // TODO: 변수를 선언한다.
        // Data type: Weapon
        // Variable name: club
        // Value: Weapon("crude spiked club")
//        t_info info;
//        Weapon club1;
        // Default Constructor
        Weapon club0 = Weapon();
        // Parameterized Constructor
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