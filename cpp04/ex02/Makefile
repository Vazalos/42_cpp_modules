# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 10:28:46 by david-fe          #+#    #+#              #
#    Updated: 2026/01/20 10:29:02 by david-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX	= c++
RM	= rm -rf
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = Abstract
SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp
OBJ_PATH = .obj
OBJ = $(addprefix $(OBJ_PATH)/, $(SRC:.cpp=.o))

all: $(OBJ_PATH) $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(OBJ_PATH)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_PATH)
	@echo "[DELETED OBJECTS]"


fclean: clean
	$(RM) $(NAME)
	@echo "[DELETED BINARY]"

re: fclean all

.PHONY: all clean fclean re
