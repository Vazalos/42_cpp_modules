# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david-fe <david-fe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/17 17:10:51 by david-fe          #+#    #+#              #
#    Updated: 2025/12/17 17:11:39 by david-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX	= c++
RM	= rm -rf
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = Fixed2
SRC = main.cpp Fixed.cpp
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