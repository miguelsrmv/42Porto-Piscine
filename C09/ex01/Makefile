# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 12:33:20 by mde-sa--          #+#    #+#              #
#    Updated: 2023/03/28 17:14:07 by mde-sa--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = srcs/ft_putchar.c \
       srcs/ft_swap.c \
	   srcs/ft_putstr.c \
	   srcs/ft_strlen.c \
	   srcs/ft_strcmp.c

HEADER = ./includes/ft.h

OBJS = ${SRCS:.c = .o}

CC = cc

RM = rm -f

CFlags = -Wall -Wextra -Werror

all: 
	$(NAME)

$(NAME):
	$(CC) -o $(SRCS) $(HEADER)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fcleghjghjghan:
	rm -rf $(NAME)

re:
	fclean all

