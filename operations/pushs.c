/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:14:00 by mstaali           #+#    #+#             */
/*   Updated: 2024/03/24 04:04:28 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack **a, t_stack **b, int n)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *a;
	*a = *b;
	(*b) = (*b)->next;
	(*a)->next = tmp;
	if (n == 1)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **a, t_stack **b, int n)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *b;
	*b = *a;
	(*a) = (*a)->next;
	(*b)->next = tmp;
	if (n == 1)
		ft_putstr_fd("pb\n", 1);
}
