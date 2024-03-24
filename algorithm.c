/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:53:33 by mstaali           #+#    #+#             */
/*   Updated: 2024/03/24 04:08:16 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	if (max(*a) == (*a)->value)
		ra(a, 1);
	else if (max(*a) == (*a)->next->value)
		rra(a, 1);
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size-- > 3)
		push_min(a, b);
	if (size-- > 3)
	{
		push_min(a, b);
		if ((*b)->value < (*b)->next->value)
			sb(b, 1);
	}
	sort_three(a);
	pa(a, b, 1);
	if (size == 3)
		pa(a, b, 1);
}

void	sort_full_stack(t_stack **a, t_stack **b)
{
	indexing(a);
	push_to_b(a, b);
	push_back_to_a(a, b);
}

void	algorithm(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 2)
		sa(a, 1);
	else if (ft_lstsize(*a) == 3)
		sort_three(a);
	else if (ft_lstsize(*a) <= 5)
		sort_five(a, b);
	else
		sort_full_stack(a, b);
}
