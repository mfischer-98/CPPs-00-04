# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/20 09:49:54 by mefische          #+#    #+#              #
#    Updated: 2026/07/20 11:34:11 by mefische         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRC = main.cpp Contact.cpp PhoneBook.cpp
OBJ = $(SRC:.cpp=.o)
CC  = c++ -Wall -Wextra -Werror -std=c++98 -g
#VAL = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
	@echo  "$(PINK)🌼 Compilation finished $(RESET)"

%.o: %.cpp
	$(CC) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "$(MINT)✨ Object files cleaned $(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(LILAC)💫 All build files removed $(RESET)"

re: fclean all

.PHONY: all clean fclean re

# Colors
PINK  = \033[38;5;205m
MINT  = \033[38;5;121m
LILAC = \033[38;5;141m
RESET = \033[0m