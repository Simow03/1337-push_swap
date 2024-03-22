/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:45:52 by mstaali           #+#    #+#             */
/*   Updated: 2024/03/21 00:58:42 by mstaali          ###   ########.fr       */
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
