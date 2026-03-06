# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/21 15:02:11 by david-fe          #+#    #+#              #
#    Updated: 2026/03/03 16:18:30 by david-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
RM = rm -rf
CXXFLAGS = -Wall -Wextra -Wextra -std=c++98

NAME = Intern
SRC = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
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