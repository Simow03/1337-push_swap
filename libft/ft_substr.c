/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:28:14 by mstaali           #+#    #+#             */
/*   Updated: 2024/03/15 03:36:38 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*ft_strdup(const char *str)
{
	char	*buffer;
	char	*b;

	buffer = (char *)malloc(ft_strlen(str) + 1);
	if (!buffer)
		return (NULL);
	b = buffer;
	while (*str)
		*b++ = *str++;
	*b = '\0';
	return (buffer);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*buffer;

	if (s == NULL)
		return (NULL);
	if (!len || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		buffer = (char *)malloc(ft_strlen(s + start) + 1);
	else
		buffer = (char *)malloc(len + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
		buffer[i++] = s[start++];
	buffer[i] = '\0';
	return (buffer);
}
