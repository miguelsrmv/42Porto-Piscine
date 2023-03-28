# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 12:33:20 by mde-sa--          #+#    #+#              #
#    Updated: 2023/03/28 18:04:41 by mde-sa--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = srcs/ft_putchar.c \
       srcs/ft_swap.c \
	   srcs/ft_putstr.c \
	   srcs/ft_strlen.c \
	   srcs/ft_strcmp.c

HEADER = ./includes/

OBJS = ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o

CC = cc

RM = rm -f

CFlags = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I $(HEADER) -c $(SRCS) 
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME)

re:
	fclean all

