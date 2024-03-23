/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:53:33 by mstaali           #+#    #+#             */
/*   Updated: 2024/03/23 02:32:45 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	if (max(*a) == (*a)->value)
		ra(a);
	else if (max(*a) == (*a)->next->value)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
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

t_stack	*largest_index(t_stack *stack)
{
	t_stack *largest;
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

void	sort_full_stack(t_stack **a, t_stack **b)
{
	indexing(a);
	push_to_b(a, b);
	push_back_to_a(a, b);
}

void	algorithm(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 2)
		sa(a);
	else if (ft_lstsize(*a) == 3)
		sort_three(a);
	else if (ft_lstsize(*a) <= 5)
		sort_five(a, b);
	else
		sort_full_stack(a, b);
}
