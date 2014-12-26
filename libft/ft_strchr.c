/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelloun <nbelloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:08:54 by nbelloun          #+#    #+#             */
/*   Updated: 2014/12/17 18:23:17 by nbelloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	if (!src)
		return (NULL);
	while ((*((char *)src) != '\0') && (*((char *)src) != (char)c))
		(char *)src++;
	if (*((char *)src) == (char)c)
		return ((char *)src);
	return (NULL);
}
