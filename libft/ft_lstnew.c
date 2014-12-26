/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelloun <nbelloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:40:52 by nbelloun          #+#    #+#             */
/*   Updated: 2014/11/19 17:01:29 by nbelloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->next = (t_list *)NULL;
	new_list->content = (void *)NULL;
	new_list->content_size = 0;
	if ((content == NULL) || (content_size <= 0))
		return (new_list);
	if (!(new_list->content = ft_memalloc(content_size)))
		return ((t_list*)(NULL));
	ft_memcpy(new_list->content, content, content_size);
	new_list->content_size = content_size;
	return (new_list);
}
