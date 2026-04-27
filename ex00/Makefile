# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crmorale <crmorale@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/27 15:42:13 by crmorale          #+#    #+#              #
#    Updated: 2026/04/27 15:42:14 by crmorale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME		:= bureaucrat
CC		:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98

SRC		:= Bureaucrat.cpp main.cpp
OBJ		:= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Bureaucrat.hpp
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
