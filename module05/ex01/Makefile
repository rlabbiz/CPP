# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 21:41:15 by rlabbiz           #+#    #+#              #
#    Updated: 2023/10/25 17:08:40 by rlabbiz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
NAME		= Bureaucrat
DFS			= Bureaucrat.hpp Form.hpp
OBJ			= main.o Bureaucrat.o Form.o

%.o: %.cpp $(DFS)
	$(C++) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJ) $(DFS)
	$(C++) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean 
	rm -rf $(NAME)

re: fclean all