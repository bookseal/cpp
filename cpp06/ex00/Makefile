# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leegichan <leegichan@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 20:43:56 by gichlee           #+#    #+#              #
#    Updated: 2024/01/06 19:44:10 by leegichan        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= a.out
SRCS		=	main.cpp \
				ScalarConverter.cpp

OBJS		= $(SRCS:%.cpp=%.o)
# CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
CXXFLAGS	+= -g

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