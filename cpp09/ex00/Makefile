# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 20:43:56 by gichlee           #+#    #+#              #
#    Updated: 2024/02/03 14:24:15 by gichlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= btc
SRCS		=	main.cpp \
				BitcoinExchange.cpp \

OBJS		= $(SRCS:%.cpp=%.o)
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
# CXXFLAGS	+= -g3

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