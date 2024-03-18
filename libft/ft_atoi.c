/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 01:24:22 by mstaali           #+#    #+#             */
/*   Updated: 2024/03/17 17:35:21 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= (-1);
	}
	if (!str[i])
		error();
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			error();
		result = (result * 10) + (str[i++] - '0');
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
			error();
	}
	return (result * sign);
}
