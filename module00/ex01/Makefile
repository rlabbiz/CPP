# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 11:56:59 by rlabbiz           #+#    #+#              #
#    Updated: 2023/09/18 23:04:38 by rlabbiz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
NAME		= phonebook
OBJ			= main.o Contact.o PhoneBook.o
DFS			= PhoneBook.hpp Contact.hpp

%.o: %.cpp
	$(C++) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJ) $(DFS)
	$(C++) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
