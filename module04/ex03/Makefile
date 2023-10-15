# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 21:41:15 by rlabbiz           #+#    #+#              #
#    Updated: 2023/10/14 20:22:06 by rlabbiz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
NAME		= AMateria
DFS			= AMateria.hpp ICharacter.hpp
OBJ			= main.o AMateria.o ICharacter.o

%.o: %.cpp $(DFS)
	$(C++) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJ) $(DFS)
	$(C++) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean 
	rm -rf $(NAME)

re: fclean all