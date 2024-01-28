#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) : std::stack<T>(other) {}

template<typename T>
MutantStack<T>::~MutantStack() {}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other) {
    if (this != &other)
        std::stack<T>::operator=(other);
    return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}

template<typename T>
void MutantStack<T>::push(const T &val) {
    this->c.push_back(val);
}

template<typename T>
void MutantStack<T>::pop() {
    this->c.pop_back();
}