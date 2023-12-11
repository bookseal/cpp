# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 20:43:56 by gichlee           #+#    #+#              #
#    Updated: 2023/12/11 15:22:32 by gichlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= a.out
SRCS		=	main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp \
				FragTrap.cpp \

OBJS		= $(SRCS:%.cpp=%.o)
CXXFLAGS	= -Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98
RM			+= -f
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY:		all clean fclean re

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:
			make clean
			$(RM) $(NAME)

re:	fclean
	$(MAKE) all