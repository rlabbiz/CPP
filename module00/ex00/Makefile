# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 11:57:51 by rlabbiz           #+#    #+#              #
#    Updated: 2023/09/15 14:33:06 by rlabbiz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
NAME 		= megaphone
OBJ			= megaphone.o

%.o: %.cpp
	$(C++) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJ)
	$(C++) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
