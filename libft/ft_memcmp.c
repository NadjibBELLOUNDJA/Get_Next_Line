/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelloun <nbelloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:40:52 by nbelloun          #+#    #+#             */
/*   Updated: 2014/11/16 18:58:02 by nbelloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		dif;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	if (n > 0)
	{
		n--;
		while (i < n)
		{
			if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			{
				dif = (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
				return (dif);
			}
			i++;
		}
		return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
	}
	return (0);
}
