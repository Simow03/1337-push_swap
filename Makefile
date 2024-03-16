# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 03:11:42 by mstaali           #+#    #+#              #
#    Updated: 2024/03/16 01:29:41 by mstaali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

M_SOURCES = main.c utils.c libft/ft_lstadd_back.c libft/ft_lstlast.c libft/ft_lstnew.c \
	libft/ft_split.c libft/ft_strlen.c libft/ft_substr.c libft/ft_putstr_fd.c \
	libft/ft_atoi.c libft/ft_lstclear.c

M_OBJECTS = $(M_SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(M_OBJECTS)
	$(CC) $(CFLAGS) $(M_OBJECTS) -o $(NAME)

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(M_OBJECTS) $(B_OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re