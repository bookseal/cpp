#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
    if (std::find(container.begin(), container.end(), n) != container.end())
        return (std::find(container.begin(), container.end(), n));
    else
        throw (std::exception());
}

#endif