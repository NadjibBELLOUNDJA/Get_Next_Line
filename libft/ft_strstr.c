/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelloun <nbelloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:42:19 by nbelloun          #+#    #+#             */
/*   Updated: 2014/11/17 13:45:33 by nbelloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	s2_len;

	if (!s1 || !s2)
		return ((char *)0);
	if (*s2 == '\0')
		return ((char *)s1);
	s2_len = ft_strlen(s2);
	while (*s1)
	{
		if (ft_memcmp(s1, s2, s2_len) == 0)
			return ((char *)s1);
		s1++;
	}
	return ((char *)0);
}
