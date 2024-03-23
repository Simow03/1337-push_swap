/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:45:52 by mstaali           #+#    #+#             */
/*   Updated: 2024/03/23 20:55:45 by mstaali          ###   ########.fr       */
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
		rb(b);
		to_push->moves--;
	}
	while (to_push->moves && to_push->moves < 0)
	{
		rrb(b);
		to_push->moves++;
	}
}

void	push_min(t_stack **a, t_stack **b)
{
	t_stack	*last;

	last = ft_lstlast(*a);
	if (min(*a) == (*a)->value)
	{
		pb(a, b);
		return ;
	}
	if (min(*a) == (*a)->next->value)
		sa(a);
	else if (min(*a) == (*a)->next->next->value)
	{
		ra(a);
		sa(a);
	}
	else if (min(*a) == last->value)
		rra(a);
	else
	{
		rra(a);
		rra(a);
	}
	pb(a, b);
}

void	push_to_b(t_stack **a, t_stack **b)
{
	int	i;
	int	z;

	i = 0;
	z = 16;
	if (ft_lstsize(*a) >= 500)
		z = 34;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->index < i + z)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else
			ra(a);
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
			pa(a, b);
			return ;
		}
		positioning(*b);
		to_push = largest_index(*b);
		if (to_push->position > (size / 2))
			to_push->moves = to_push->position - size;
		else
			to_push->moves = to_push->position;
		swap_to_top(to_push, b);
		pa(a, b);
		size--;
	}
}
