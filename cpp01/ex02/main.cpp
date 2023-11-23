#include <iostream>
#include <string>

int main(void){
	std::string str = "HI THIS IS BRAIN";
	// make stringPTR a pointer to the string.
	std::string* stringPTR = &str;
	// make stringREF a reference to the string.
	std::string& stringREF = str;

	// The momory address of the string variable
	std::cout << &str << std::endl;
	// The memory address held by stringPTR
	std::cout << stringPTR << std::endl;
	// The memory address held by stringREF
	std::cout << &stringREF << std::endl;

	std::cout << std::endl;

	// The value of the string variable.
	std::cout << str << std::endl;
	// The value pointed to by stringPTR.
	std::cout << *stringPTR << std::endl;
	// The value pointed to by stringREF.
	std::cout << stringREF << std::endl;
	
	std::cout << std::endl;
	
	str = "MODIFIED";
	// The value of the string variable.
	std::cout << str << std::endl;
	// The value pointed to by stringPTR.
	std::cout << *stringPTR << std::endl;
	// The value pointed to by stringREF.
	std::cout << stringREF << std::endl;
	return (0);
}