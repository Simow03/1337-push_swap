/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:06:03 by mstaali           #+#    #+#             */
/*   Updated: 2024/04/23 16:16:48 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	fill_stack_quoted(char *av, t_stack **a)
{
	char	**numbers;
	int		i;
	int		num;

	numbers = ft_split(av, ' ');
	i = 0;
	while (numbers[i])
	{
		num = ft_atoi(numbers[i]);
		ft_lstadd_back(a, ft_lstnew(&num));
		i++;
	}
	i = 0;
	while (numbers[i])
		free(numbers[i++]);
	free(numbers);
}

static t_stack	*fill_stack(int ac, char **av)
{
	t_stack	*a;
	int		i;
	int		j;

	a = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		error();
	else
	{
		i = 1;
		while (i < ac)
		{
			j = 0;
			while (ft_iswhitespace(av[i][j]))
				j++;
			if (!av[i][j])
				error();
			fill_stack_quoted(av[i], &a);
			i++;
		}
	}
	return (a);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (EXIT_FAILURE);
	a = fill_stack(ac, av);
	b = NULL;
	if (!a || is_duplicate(a))
	{
		ft_lstclear(&a, free);
		error();
	}
	if (!is_sorted(a))
		algorithm(&a, &b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (EXIT_SUCCESS);
}
