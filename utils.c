/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 01:28:29 by mstaali           #+#    #+#             */
/*   Updated: 2024/03/20 03:43:41 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	ft_iswhitespace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f');
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
