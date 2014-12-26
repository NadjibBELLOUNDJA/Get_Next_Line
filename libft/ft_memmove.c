/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelloun <nbelloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:40:52 by nbelloun          #+#    #+#             */
/*   Updated: 2014/11/28 17:12:22 by nbelloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*src_char;
	unsigned char	src_copy[len];

	if (!dest)
		return (NULL);
	if (src != NULL)
	{
		src_char = (unsigned char *)src;
		i = 0;
		while (i < len)
		{
			src_copy[i] = src_char[i];
			i++;
		}
		i = 0;
		while (i < len)
		{
			((char *)dest)[i] = ((char*)src_copy)[i];
			i++;
		}
	}
	return (dest);
}
