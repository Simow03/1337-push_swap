/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:45:52 by mstaali           #+#    #+#             */
/*   Updated: 2024/04/23 16:14:17 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*largest_index(t_stack *stack)
{
	t_stack	*largest;
	int		index;

	index = 0;
	while (stack != NULL)
	{
		if (index < stack->index)
		{
			largest = stack;
			index = stack->index;
		}
		stack = stack->next;
	}
	return (largest);
}

void	swap_to_top(t_stack *to_push, t_stack **b)
{
	while (to_push->moves && to_push->moves > 0)
	{
		rb(b, 1);
		to_push->moves--;
	}
	while (to_push->moves && to_push->moves < 0)
	{
		rrb(b, 1);
		to_push->moves++;
	}
}

void	push_min(t_stack **a, t_stack **b)
{
	t_stack	*last;

	last = ft_lstlast(*a);
	if (min(*a) == (*a)->value)
	{
		pb(a, b, 1);
		return ;
	}
	if (min(*a) == (*a)->next->value)
		sa(a, 1);
	else if (min(*a) == (*a)->next->next->value)
	{
		ra(a, 1);
		sa(a, 1);
	}
	else if (min(*a) == last->value)
		rra(a, 1);
	else
	{
		rra(a, 1);
		rra(a, 1);
	}
	pb(a, b, 1);
}

void	push_to_b(t_stack **a, t_stack **b)
{
	int	i;
	int	z;

	i = 0;
	z = 16;
	if (ft_lstsize(*a) >= 100)
		z = 34;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b, 1);
			i++;
		}
		else if ((*a)->index < i + z)
		{
			pb(a, b, 1);
			rb(b, 1);
			i++;
		}
		else
			ra(a, 1);
	}
}

void	push_back_to_a(t_stack **a, t_stack **b)
{
	t_stack	*to_push;
	int		size;

	size = ft_lstsize(*b);
	while (size)
	{
		if (size == 1)
		{
			pa(a, b, 1);
			return ;
		}
		positioning(*b);
		to_push = largest_index(*b);
		if (to_push->position > (size / 2))
			to_push->moves = to_push->position - size;
		else
			to_push->moves = to_push->position;
		swap_to_top(to_push, b);
		pa(a, b, 1);
		size--;
	}
}
