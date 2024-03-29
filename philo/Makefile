#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 12:48:46 by francfer          #+#    #+#              #
#    Updated: 2024/03/29 12:41:23 by francfer         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME    = philo
CC      = gcc
CFLAGS  = -Wall -Werror -Wextra -pthread
RM      = rm -rf

GREEN   := \033[0;32m
PINK    := \033[1;35m
NC      := \033[0m

FILES   = main.c parser.c utils.c utils1.c init.c safe_functions.c
OBJS    = $(FILES:.c=.o)

all: $(NAME)

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)
	@echo "$(PINK)Philo ready!$(NC)"

clean:
	@echo "$(GREEN)Cleaning...!$(NC)"
	$(RM) $(OBJS)

fclean: clean
	@echo "$(GREEN)FCleaning...$(NC)"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
