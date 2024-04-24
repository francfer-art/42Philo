# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 12:27:12 by francfer          #+#    #+#              #
#    Updated: 2024/04/24 16:25:27 by francfer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = philo_bonus
CC      = gcc -g
CFLAGS  = -Wall -Werror -Wextra -pthread
RM      = rm -rf

GREEN   := \033[0;32m
PINK    := \033[1;35m
NC      := \033[0m

FILES   = init_bonus.c main_bonus.c utils_bonus.c utils1_bonus.c \
dinner_bonus.c monitoring_bonus.c
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