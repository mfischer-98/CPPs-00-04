# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/23 09:39:44 by mefische          #+#    #+#              #
#    Updated: 2026/07/23 11:58:22 by mefische         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace

SRC = main.cpp StringReplace.cpp
OBJ = $(SRC:.cpp=.o)
CC  = c++ -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
	@echo  "$(PINK)🌼 Compilation finished $(RESET)"

%.o: %.cpp
	$(CC) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "$(LILAC)✨ Object files cleaned $(RESET)"

fclean: clean
	@rm -f $(NAME)
	@find . -name "*.replace" -type f -delete
	@echo "$(MINT)💫 All build files removed $(RESET)"

re: fclean all

.PHONY: all clean fclean re

# Colors
PINK  = \033[38;5;205m
MINT  = \033[38;5;121m
LILAC = \033[38;5;141m
RESET = \033[0m