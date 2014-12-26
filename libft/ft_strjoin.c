/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelloun <nbelloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:40:52 by nbelloun          #+#    #+#             */
/*   Updated: 2014/11/21 18:51:37 by nbelloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_new;
	size_t	len;
	size_t	i;

	if (s1 == NULL && s2 == NULL)
		return ((char *)NULL);
	if (s1 == NULL && s2)
		return (ft_strdup(s2));
	if (s2 == NULL && s1)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s_new = ft_strnew(len);
	if (!s_new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (i < ft_strlen(s1))
			s_new[i] = s1[i];
		else
			s_new[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	return (s_new);
}
