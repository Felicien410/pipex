# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 17:58:51 by fcatteau          #+#    #+#              #
#    Updated: 2022/11/26 14:42:07 by fcatteau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_putchar.c \
		ft_putstr.c \
		ft_strlen.c \
		ft_putnbr_base.c \
		ft_printf.c \
		ft_put_adresse.c \
		ft_putnbr.c \
		ft_put_hexa.c \

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I ./

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		ar -rcs ${NAME} ${OBJS}

all: 	${NAME}

clean:	
		rm -f ${OBJS}

fclean:	clean;
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re 