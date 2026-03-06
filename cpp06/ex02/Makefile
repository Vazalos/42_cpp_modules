# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/05 10:18:28 by david-fe          #+#    #+#              #
#    Updated: 2026/03/05 12:42:04 by david-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
RM = rm -rf
CXXFLAGS = -Wall -Wextra -Wextra -std=c++98

NAME = Identify
SRC = Base.cpp main.cpp
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