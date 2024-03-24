/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 03:45:41 by mstaali           #+#    #+#             */
/*   Updated: 2024/03/24 03:46:10 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strjoin(char *stored, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!stored)
	{
		stored = (char *)malloc(1);
		stored[0] = '\0';
	}
	if (!stored || !buffer)
		return (NULL);
	str = (char *)malloc(ft_strlen(stored) + ft_strlen(buffer) + 1);
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (stored)
		while (stored[++i] != '\0')
			str[i] = stored[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen(stored) + ft_strlen(buffer)] = '\0';
	free(stored);
	return (str);
}
