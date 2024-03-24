/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:18:14 by mstaali           #+#    #+#             */
/*   Updated: 2024/03/24 04:07:42 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack **a, int n)
{
	t_stack	*tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (n == 1)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b, int n)
{
	t_stack	*tmp;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (n == 1)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b, int n)
{
	sa(a, 0);
	sb(b, 0);
	if (n == 1)
		ft_putstr_fd("ss\n", 1);
}
