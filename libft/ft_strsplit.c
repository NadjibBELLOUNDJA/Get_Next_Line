/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelloun <nbelloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:40:52 by nbelloun          #+#    #+#             */
/*   Updated: 2014/11/28 17:59:46 by nbelloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getword(char const *s, char c, size_t *start, size_t len)
{
	size_t			i;

	i = *start + len;
	while (*(s + i) == c)
		i++;
	*start = i;
	while (*(s + i) != c && *(s + i) != '\0')
		i++;
	return (i - *start);
}

static void		ft_initialize(size_t *count, size_t *start, size_t *len)
{
	*count = 0;
	*start = 0;
	*len = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	char			**w;
	size_t			count;
	size_t			start;
	size_t			len;
	size_t			i;

	ft_initialize(&count, &start, &len);
	if (!s || !c)
		return (NULL);
	while ((len = ft_getword(s, c, &start, len)) != 0)
		count++;
	if ((w = (char **)malloc(sizeof(*w) * (count + 1))) == NULL)
		return (NULL);
	start = 0;
	i = 0;
	while (i < count)
	{
		len = ft_getword(s, c, &start, len);
		if ((*(w + i) = ft_strsub(s, start, len)) == NULL)
			return (NULL);
		i++;
	}
	*(w + i) = NULL;
	return (w);
}
