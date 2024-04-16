# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 12:30:34 by francfer          #+#    #+#              #
#    Updated: 2024/04/16 12:51:41 by francfer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = philo_bonus
CC      = gcc
CFLAGS  = -Wall -Werror -Wextra -pthread
RM      = rm -rf

GREEN   := \033[0;32m
PINK    := \033[1;35m
NC      := \033[0m

FILES   = main_bonus.c parser_bonus.c utils_bonus.c utils1_bonus.c
OBJS    = $(FILES:.c=.o)

all: $(NAME)

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)
	@echo "$(PINK)Philo Bonus ready!$(NC)"

clean:
	@echo "$(GREEN)Cleaning...!$(NC)"
	$(RM) $(OBJS)

fclean: clean
	@echo "$(GREEN)FCleaning...$(NC)"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
