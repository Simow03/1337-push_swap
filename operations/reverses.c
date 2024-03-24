/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverses.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:21:14 by mstaali           #+#    #+#             */
/*   Updated: 2024/03/24 04:07:30 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack **a, int n)
{
	t_stack	*tmp;
	int		size;

	if (!*a || !(*a)->next)
		return ;
	size = ft_lstsize(*a) - 1;
	tmp = (*a);
	*a = ft_lstlast(*a);
	(*a)->next = tmp;
	while (size > 1)
	{
		tmp = tmp->next;
		size--;
	}
	tmp->next = NULL;
	if (n == 1)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b, int n)
{
	t_stack	*tmp;
	int		size;

	if (!*b || !(*b)->next)
		return ;
	size = ft_lstsize(*b) - 1;
	tmp = (*b);
	(*b) = ft_lstlast(*b);
	(*b)->next = tmp;
	while (size > 1)
	{
		tmp = tmp->next;
		size--;
	}
	tmp->next = NULL;
	if (n == 1)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b, int n)
{
	rra(a, 0);
	rrb(b, 0);
	if (n == 1)
		ft_putstr_fd("rrr\n", 1);
}
