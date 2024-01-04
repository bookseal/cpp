
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <string>

void pause(std::string msg)
{
	std::cout << msg;
	std::cin.get();
}

Base *generate(void)
{
	srand(time(NULL));
	int i = rand() % 3;

	if (i == 0)
	{
		std::cout << "A generated" << std::endl;
		return (new A());
	}
	else if (i == 1)
	{
		std::cout << "B generated" << std::endl;
		return (new B());
	}
	else
	{
		std::cout << "C generated" << std::endl;
		return (new C());
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch (std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
			(void)b;
		}
		catch (std::exception &e)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
				(void)c;
			}
			catch (std::exception &e)
			{
				std::cout << "Unknown" << std::endl;
			}
		}
	}
}

int main(void)
{
	{
		Base *base = generate();

		pause("Press ENTER to identify base...");
		identify(base);
		identify(*base);
		std::cout << std::endl;
	}
	{
		Base *base = generate();

		pause("Press ENTER to identify base...");
		identify(base);
		identify(*base);
		std::cout << std::endl;
	}
	{
		Base *base = generate();

		pause("Press ENTER to identify base...");
		identify(base);
		identify(*base);
		std::cout << std::endl;
	}
	return (0);
}