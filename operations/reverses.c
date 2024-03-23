/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverses.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:21:14 by mstaali           #+#    #+#             */
/*   Updated: 2024/03/23 01:50:40 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack **a)
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
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b)
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
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	ft_putstr_fd("rrr\n", 1);
}
