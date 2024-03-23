/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:31:35 by mstaali           #+#    #+#             */
/*   Updated: 2024/03/23 21:50:57 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	(*a) = ft_lstlast(*a);
	(*a)->next = tmp;
	(*a) = tmp->next;
	tmp->next = NULL;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b)
{
	t_stack	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	(*b) = ft_lstlast(*b);
	(*b)->next = tmp;
	(*b) = tmp->next;
	tmp->next = NULL;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	ft_putstr_fd("rr\n", 1);
}
