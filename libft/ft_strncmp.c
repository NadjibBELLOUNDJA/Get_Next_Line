/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelloun <nbelloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:05:33 by nbelloun          #+#    #+#             */
/*   Updated: 2014/11/16 20:13:50 by nbelloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (0);
	i = 0;
	n--;
	while ((*s1 == *s2++) && (i < n))
	{
		if (*s1 == 0)
			return (0);
		s1++;
		i++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
