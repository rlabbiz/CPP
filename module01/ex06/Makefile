# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 10:35:27 by rlabbiz           #+#    #+#              #
#    Updated: 2023/09/27 16:08:41 by rlabbiz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
NAME		= harlFilter
OBJ			= main.o Harl.o
DFS			= Harl.hpp

%.o: %.cpp $(DFS)
	$(C++) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(MAIN_FILE) $(OBJ) $(DFS)
	$(C++) $(MAIN_FILE) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean 
	rm -rf $(NAME)

re: fclean all