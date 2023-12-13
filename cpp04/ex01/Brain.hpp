#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	public:
		Brain();
		Brain(const Brain& copy);
		~Brain();
		Brain& operator=(const Brain& op);
		std::string getIdea(int index) const;
		void setIdea(int index, std::string idea);
	private:
		std::string ideas[100];
};

#endif