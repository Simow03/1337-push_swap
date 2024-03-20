/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:53:33 by mstaali           #+#    #+#             */
/*   Updated: 2024/03/20 03:55:22 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(t_stack *a)
{
	int	max;

	max = a->value;
	while (a != NULL)
	{
		if (max < a->value)
			max = a->value;
		a = a->next;
	}
	return (max);
}

int	min(t_stack *a)
{
	int	min;

	min = a->value;
	while (a != NULL)
	{
		if (min > a->value)
			min = a->value;
		a = a->next;
	}
	return (min);
}

void	sort_three(t_stack **a)
{
	if (max(*a) == (*a)->value)
		ra(a);
	else if (max(*a) == (*a)->next->value)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	push_min(t_stack **a, t_stack **b)
{
	t_stack *last = ft_lstlast(*a);
	if (min(*a) == (*a)->next->value)
		sa(a);
	if (min(*a) == (*a)->next->next->value)
	{
		ra(a);
		sa(a);
	}
	if (min(*a) == last->value)
		rra(a);
	pb(a, b);
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
			sb(b);
	}
	sort_three(a);
	pa(a, b);
	if (size == 3)
		pa(a, b);
}

void	algorithm(t_stack **a)
{
	t_stack *b;

	if (ft_lstsize(*a) == 2)
		sa(a);
	else if (ft_lstsize(*a) == 3)
		sort_three(a);
	else if (ft_lstsize(*a) <= 5)
		sort_five(a, &b);
}
