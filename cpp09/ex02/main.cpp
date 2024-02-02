#include "MutantStack.hpp"
#include <iostream>
#include <string>
#include <stack>
#include <list>

void pause(std::string msg)
{
	std::cout << "====================" << std::endl;
	std::cout << msg << std::endl;
	std::cout << "Press ENTER to continue...";
	std::cin.get();
}

int	main(void)
{
	pause("Testing with a mutantstack of ints");
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "Top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	pause("Testing with a list of ints");
	{
		std::list <int> l;
		l.push_back(5);
		l.push_back(17);
		std::cout << "Top: " << l.back() << std::endl;
		l.pop_back();
		std::cout << "Size: " << l.size() << std::endl;
		l.push_back(3);
		l.push_back(5);
		l.push_back(737);
		l.push_back(0);
		std::list<int>::iterator itl = l.begin();
		std::list<int>::iterator itel = l.end();
		++itl;
		--itl;
		while (itl != itel)
		{
			std::cout << *itl << std::endl;
			++itl;
		}
		std::list<int> sl(l);
	}

	return (0);
}