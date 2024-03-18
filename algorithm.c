/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:53:33 by mstaali           #+#    #+#             */
/*   Updated: 2024/03/18 17:39:09 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_three(t_stack **a)
{
	t_stack	*tmp;

	tmp = ft_lstlast(*a);
	if (min(*a) == (*a)->value)
	{
		sa(a);
		ra(a);
	}
	else if (max(*a) == (*a)->value && min(*a) == tmp->value)
	{
		sa(a);
		rra(a);
	}
	else if (max(*a) == tmp->value)
		sa(a);
	else if (max(*a) == (*a)->next->value && min(*a) == tmp->value)
		rra(a);
	else if (max(*a) == (*a)->value && min(*a) == (*a)->next->value)
		ra(a);
}

void	algorithm(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (ft_lstsize(*a) == 2)
		sa(a);
	if (ft_lstsize(*a) == 3 && !is_sorted(*a))
		sort_three(a);
}
