# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 21:41:15 by rlabbiz           #+#    #+#              #
#    Updated: 2023/10/12 14:06:43 by rlabbiz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
NAME		= Brain
DFS			= Animal.hpp Cat.hpp Dog.hpp Brain.hpp
OBJ			= main.o Animal.o Cat.o Dog.o Brain.o

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