# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 03:11:42 by mstaali           #+#    #+#              #
#    Updated: 2024/03/22 17:12:29 by mstaali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

M_SOURCES = main.c utils.c algorithm.c algo_utils.c indexing.c operations/swaps.c operations/rotates.c \
	operations/pushs.c operations/reverses.c libft/ft_split.c libft/ft_strlen.c libft/ft_substr.c \
	libft/ft_atoi.c libft/ft_lstclear.c libft/ft_lstnew.c libft/ft_lstsize.c libft/ft_lstadd_back.c \
	libft/ft_lstlast.c libft/ft_iswhitespace.c libft/ft_putstr_fd.c

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