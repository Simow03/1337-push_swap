/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 00:21:08 by mstaali           #+#    #+#             */
/*   Updated: 2024/03/16 01:38:34 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/* Utils */
void	error(void);
int		is_duplicate(t_stack *a);
int		is_sorted(t_stack *a);

/* Libft */
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
t_stack	*ft_lstnew(int *value);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstclear(t_stack **lst, void (*del)(void *));
void	ft_lstadd_back(t_stack **lst, t_stack *new);

#endif