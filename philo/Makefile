# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/28 09:05:59 by jaebae            #+#    #+#              #
#    Updated: 2022/07/12 09:39:03 by jaebae           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAG = -Wall -Wextra -Werror -I include -g

SRC = srcs/

SRCS = \
$(SRC)main.c \
$(SRC)utils.c \
$(SRC)ft_atoi.c \
$(SRC)ft_atol.c \
$(SRC)init_utils.c \
$(SRC)action.c \
$(SRC)philo_run.c \
$(SRC)monitor_run.c \

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
