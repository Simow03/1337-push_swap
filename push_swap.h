/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 00:21:08 by mstaali           #+#    #+#             */
/*   Updated: 2024/03/24 04:18:39 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

/* stack */
typedef struct s_stack
{
	int				value;
	int				index;
	int				position;
	int				moves;
	struct s_stack	*next;
}	t_stack;

/* Operations */
void	sa(t_stack **a, int n);
void	sb(t_stack **b, int n);
void	ss(t_stack **a, t_stack **b, int n);
void	ra(t_stack **a, int n);
void	rb(t_stack **a, int n);
void	rr(t_stack **a, t_stack **b, int n);
void	pa(t_stack **a, t_stack **b, int n);
void	pb(t_stack **a, t_stack **b, int n);
void	rra(t_stack **a, int n);
void	rrb(t_stack **b, int n);
void	rrr(t_stack **a, t_stack **b, int n);

/* Algorithm */
void	indexing(t_stack **a);
void	give_index(t_stack *a, int index, int value);
int		next_min(t_stack *stack, int min_value);

/* Utils */
void	error(void);
void	algorithm(t_stack **a, t_stack **b);
int		is_duplicate(t_stack *a);
int		is_sorted(t_stack *stack);
int		max(t_stack *stack);
int		min(t_stack *stack);
void	push_min(t_stack **a, t_stack **b);
void	push_to_b(t_stack **a, t_stack **b);
void	push_back_to_a(t_stack **a, t_stack **b);
t_stack	*largest_index(t_stack *stack);
void	swap_to_top(t_stack *to_push, t_stack **b);
void	positioning(t_stack *stack);

/* Libft */
int		ft_iswhitespace(int c);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char *stored, char *buffer);
char	*ft_strchr(char *s, int c);
int		ft_strncmp(const char *str1, const char *str2, size_t size);
t_stack	*ft_lstnew(int *value);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);
void	ft_lstclear(t_stack **lst, void (*del)(void *));
void	ft_lstadd_back(t_stack **lst, t_stack *new);

/* bonus */
# define BUFFER_SIZE 10240

char	*get_next_line(int fd);
char	*compare(t_stack **a, t_stack **b, char *line);

#endif