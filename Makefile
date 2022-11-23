# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 18:51:05 by chabrune          #+#    #+#              #
#    Updated: 2022/11/14 18:51:05 by chabrune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ft_print_addr.c \
				ft_printf.c \
				ft_print_char.c \
				ft_print_nbr.c \
				ft_print_nbr_base.c \
				ft_print_str.c \
				ft_print_u_nbr.c \
				ft_print_percent.c \

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)