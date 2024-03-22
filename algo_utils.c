/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:45:52 by mstaali           #+#    #+#             */
/*   Updated: 2024/03/22 21:18:46 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min(t_stack **a, t_stack **b)
{
	t_stack	*last;

	last = ft_lstlast(*a);
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
