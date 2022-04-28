# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/28 09:05:59 by jaebae            #+#    #+#              #
#    Updated: 2022/04/28 10:17:49 by jaebae           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAG = -Wall -Wextra -Werror -g

SRC = 
SRCS = \
$(SRC)main.c \
$(SRC)utils.c \
$(SRC)utils2.c \
$(SRC)ft_atoi.c \
$(SRC)ft_atol.c \
$(SRC)init_utils.c \
$(SRC)action.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(OBJS)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

re : fclean all

$(NAME) : $(OBJS) $(LIB)
	$(CC) $(CFLAG) -o $@ $^

.PHONY : re fclean clean all 
