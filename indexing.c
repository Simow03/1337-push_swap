/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:11:43 by mstaali           #+#    #+#             */
/*   Updated: 2024/03/23 20:57:03 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_min(t_stack *stack, int min_value)
{
	int	next;

	next = max(stack);
	while (stack != NULL)
	{
		if (stack->value > min_value && next > stack->value)
			next = stack->value;
		stack = stack->next;
	}
	return (next);
}

void	give_index(t_stack *a, int index, int value)
{
	while (a->value != value)
		a = a->next;
	a->index = index;
}

void	indexing(t_stack **a)
{
	t_stack	*tmp;
	int		min_value;
	int		next;
	int		i;

	i = 0;
	tmp = (*a);
	min_value = min(*a);
	give_index((*a), i++, min_value);
	while (tmp != NULL)
	{
		next = next_min((*a), min_value);
		if (next == min_value)
			return ;
		give_index((*a), i++, next);
		min_value = next;
		tmp = tmp->next;
	}
}
