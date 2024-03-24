# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 03:11:42 by mstaali           #+#    #+#              #
#    Updated: 2024/03/24 04:16:05 by mstaali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_B = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

M_SOURCES = main.c utils.c algorithm.c algo_utils.c indexing.c operations/swaps.c operations/rotates.c \
	operations/pushs.c operations/reverses.c libft/ft_split.c libft/ft_strlen.c libft/ft_substr.c \
	libft/ft_atoi.c libft/ft_lstclear.c libft/ft_lstnew.c libft/ft_lstsize.c libft/ft_lstadd_back.c \
	libft/ft_lstlast.c libft/ft_iswhitespace.c libft/ft_putstr_fd.c

B_SOURCES = bonus/checker_bonus.c bonus/utils_bonus.c utils.c operations/swaps.c operations/rotates.c \
	operations/pushs.c operations/reverses.c libft/ft_atoi.c libft/ft_lstclear.c libft/ft_lstnew.c \
	libft/ft_lstlast.c libft/ft_iswhitespace.c libft/ft_putstr_fd.c libft/ft_substr.c libft/ft_split.c \
	libft/ft_strlen.c libft/ft_lstsize.c libft/ft_lstadd_back.c libft/ft_strchr.c libft/ft_strjoin.c \
	libft/ft_strncmp.c

M_OBJECTS = $(M_SOURCES:.c=.o)

B_OBJECTS = $(B_SOURCES:.c=.o)

all : $(NAME)

bonus : $(NAME_B)

$(NAME) : $(M_OBJECTS)
	$(CC) $(CFLAGS) $(M_OBJECTS) -o $(NAME)

$(NAME_B) : $(B_OBJECTS)
	$(CC) $(CFLAGS) $(B_OBJECTS) -o $(NAME_B)

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

%bonus/.o : %bonus/.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(M_OBJECTS) $(B_OBJECTS)

fclean : clean
	rm -f $(NAME) $(NAME_B)

re : fclean all

.PHONY : all bonus clean fclean re