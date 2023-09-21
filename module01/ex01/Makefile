# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/09 17:10:19 by rlabbiz           #+#    #+#              #
#    Updated: 2023/09/21 00:05:49 by rlabbiz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++			= c++ 
FLAGS       = -Wall -Wextra -Werror -std=c++98
NAME		= Zombie
OBJ			= main.o Zombie.o zombieHorde.o
DFS			= Zombie.hpp

%.o: %.cpp
	$(C++) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(MAIN_FILE) $(OBJ) $(DFS)
	$(C++) $(MAIN_FILE) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean 
	rm -rf $(NAME)

re: fclean all
