/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelloun <nbelloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:44:13 by nbelloun          #+#    #+#             */
/*   Updated: 2014/11/14 20:54:37 by nbelloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2++)
	{
		if (*s1 == 0)
			return (0);
		s1++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
