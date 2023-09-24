# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 20:43:56 by gichlee           #+#    #+#              #
#    Updated: 2023/09/03 15:50:53 by gichlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= moar_brainz
SRCS		=	main.cpp \
				Zombie.cpp \
				zombieHorde.cpp 

OBJS		= $(SRCS:%.cpp=%.o)
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
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
	$(MAKE) all%