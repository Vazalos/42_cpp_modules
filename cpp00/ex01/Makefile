# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/28 16:23:33 by david-fe          #+#    #+#              #
#    Updated: 2025/10/29 13:52:50 by david-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX	= c++
RM		= rm -f
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98

NAME = PhoneBook
SRC = $(NAME).cpp Contact.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

