#include "Span.hpp"

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(Span const &src) : _n(src._n), _v(src._v) {}

Span::~Span() {}

Span &Span::operator=(Span const &rhs)
{
    if (this != &rhs)
    {
        this->_n = rhs._n;
        this->_v = rhs._v;
    }
    return (*this);
}

void Span::addNumber(int n)
{
    if (this->_v.size() < this->_n)
        this->_v.push_back(n);
    else
        throw std::exception();
}

int Span::shortestSpan()
{
    if (this->_v.size() < 2)
        throw std::exception();
    std::vector<int> v = this->_v;
    std::sort(v.begin(), v.end());
    int min = v[1] - v[0];
    for (unsigned int i = 2; i < v.size(); i++)
    {
        if (v[i] - v[i - 1] < min)
            min = v[i] - v[i - 1];
    }
    return (min);
}

int Span::longestSpan()
{
    if (this->_v.size() < 2)
        throw std::exception();
    std::vector<int> v = this->_v;
    std::sort(v.begin(), v.end());
    return (v[v.size() - 1] - v[0]);
}