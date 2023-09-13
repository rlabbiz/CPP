# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/09 17:10:19 by rlabbiz           #+#    #+#              #
#    Updated: 2023/09/12 14:56:08 by rlabbiz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++			= c++ -Wall -Wextra -Werror -std=c++98
NAME		= out
SRC			= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
DFS			= Weapon.hpp HumanA.hpp HumanB.hpp
OBJ			:= $(SRC:.cpp=.o)

all : $(NAME)

$(NAME): $(MAIN_FILE) $(OBJ) $(DFS)
	$(C++) $(MAIN_FILE) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean 
	rm -rf $(NAME)

re: fclean all
