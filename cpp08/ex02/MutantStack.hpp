#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(MutantStack const &src);
        ~MutantStack();
        MutantStack &operator=(MutantStack const &rhs);

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin();
        iterator end();

        void push(T const &val);
        void pop();
};

#include "MutantStack.tpp"

#endif