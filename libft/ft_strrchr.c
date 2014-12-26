/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelloun <nbelloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:29:45 by nbelloun          #+#    #+#             */
/*   Updated: 2014/11/14 22:42:16 by nbelloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int	len;

	if (!(char *)src)
		return (NULL);
	len = ft_strlen((char *)src);
	while (len >= 0)
	{
		if (*((char *)src + len) == (char)c)
			return ((char *)src + len);
		len--;
	}
	return (NULL);
}
