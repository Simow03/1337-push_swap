/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 01:28:29 by mstaali           #+#    #+#             */
/*   Updated: 2024/03/23 20:53:31 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	positioning(t_stack *stack)
{
	int	position;

	position = 0;
	while (stack != NULL)
	{
		stack->position = position++;
		stack = stack->next;
	}
}

int	is_duplicate(t_stack *a)
{
	t_stack	*cmp;

	while (a != NULL)
	{
		cmp = a->next;
		while (cmp != NULL)
		{
			if (a->value == cmp->value)
				return (1);
			cmp = cmp->next;
		}
		a = a->next;
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*tmp;
	int		curr_val;
	int		next_val;

	tmp = stack;
	while (tmp && tmp->next)
	{
		curr_val = tmp->value;
		next_val = tmp->next->value;
		if (curr_val > next_val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	max(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack != NULL)
	{
		if (max < stack->value)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	min(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack != NULL)
	{
		if (min > stack->value)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}
