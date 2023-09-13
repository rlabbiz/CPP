# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 11:56:59 by rlabbiz           #+#    #+#              #
#    Updated: 2023/09/08 15:31:44 by rlabbiz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

G++			= c++ -Wall -Wextra -Werror -std=c++98
NAME		= phonebook
SRC			= phonebook.cpp phonebook.class.cpp
DFS			= phonebook.hpp

all : $(NAME)

$(NAME): $(SRC) $(DFS)
	$(G++) $(SRC) -o $(NAME)

fclean: 
	rm -rf $(NAME)
