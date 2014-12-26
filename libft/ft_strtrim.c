/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelloun <nbelloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:40:52 by nbelloun          #+#    #+#             */
/*   Updated: 2014/11/19 14:17:16 by nbelloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_startindex(char const *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t'))
		i++;
	return (i);
}

static int	ft_endindex(char const *s)
{
	int	j;

	if (s == NULL)
		return (0);
	j = ft_strlen(s) - 1;
	if (ft_strlen(s) == 0 || ft_strlen(s) == 1)
		return (0);
	while ((s[j] == ' ') || (s[j] == '\n') || (s[j] == '\t'))
		j--;
	return (j);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		len;
	char	*dest;

	if (!s)
		return (NULL);
	start = ft_startindex(s);
	end = ft_endindex(s);
	if (end < start)
	{
		dest = malloc(1);
		if (!dest)
			return (NULL);
		*dest = (char)'\0';
		return (dest);
	}
	len = end - start + 1;
	dest = ft_strsub(s, start, (size_t)len);
	if (dest == NULL)
		return (NULL);
	return (dest);
}
