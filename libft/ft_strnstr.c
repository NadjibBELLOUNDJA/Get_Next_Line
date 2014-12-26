/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelloun <nbelloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:40:56 by nbelloun          #+#    #+#             */
/*   Updated: 2014/11/17 16:53:26 by nbelloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	s2_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	if (*s2 == '\0')
		return ((char *)s1);
	i = 0;
	s2_len = ft_strlen(s2);
	while (*s1 && (i < n))
	{
		if (ft_strncmp(s1, s2, s2_len) == 0)
		{
			if ((i + s2_len) > n)
				return (NULL);
			return ((char *)s1);
		}
		s1++;
		i++;
	}
	return (NULL);
}
