/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:18:14 by mstaali           #+#    #+#             */
/*   Updated: 2024/03/18 14:43:42 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b)
{
	t_stack	*tmp;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	ft_putstr_fd("ss\n", 1);
}
