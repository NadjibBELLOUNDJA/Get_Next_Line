/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelloun <nbelloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 09:54:06 by nbelloun          #+#    #+#             */
/*   Updated: 2014/11/29 14:03:16 by nbelloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		fill_buffer(int fd, char **static_buff_ptr)
{
	int			ret;
	char		*tmp;
	char		*tmp_cpy;

	*static_buff_ptr = ft_strnew(1000000);
	tmp = ft_strnew(1);
	while ((ret = read(fd, *static_buff_ptr, BUFF_SIZE)) > 0)
	{
		(*static_buff_ptr)[ret] = '\0';
		tmp_cpy = ft_strdup(tmp);
		free(tmp);
		tmp = ft_strjoin(tmp_cpy, *static_buff_ptr);
		free(tmp_cpy);
		if (ft_strchr(*static_buff_ptr, '\n'))
			break ;
	}
	*static_buff_ptr = ft_strdup(tmp);
	free(tmp);
	return (ret);
}

static size_t	get_n_index(int fd, char **static_buff_ptr)
{
	size_t		n_index;
	char		*tmp;
	char		*static_buff_ptr_cpy;
	int			ret;

	ret = 1;
	static_buff_ptr_cpy = ft_strdup(*static_buff_ptr);
	ft_strchr(static_buff_ptr_cpy, '\n');
	while (!(ft_strchr(*static_buff_ptr, '\n')) && (ret > 0))
	{
		tmp = ft_strdup(*static_buff_ptr);
		ret = fill_buffer(fd, static_buff_ptr);
		free(static_buff_ptr_cpy);
		static_buff_ptr_cpy = ft_strdup(*static_buff_ptr);
		free(*static_buff_ptr);
		*static_buff_ptr = ft_strjoin(tmp, static_buff_ptr_cpy);
		free(static_buff_ptr_cpy);
		free(tmp);
		tmp = NULL;
	}
	if (ft_strchr(*static_buff_ptr, '\n'))
		n_index = ft_strchr(*static_buff_ptr, '\n') - *static_buff_ptr;
	else
		n_index = ft_strlen(*static_buff_ptr);
	return (n_index);
}

static int		fill_line(int fd, char **line_ptr, char **static_buff_ptr)
{
	size_t		n_index;
	size_t		len;
	char		*static_buff_ptr_cpy;

	n_index = get_n_index(fd, static_buff_ptr);
	*line_ptr = ft_strsub(*static_buff_ptr, 0, n_index);
	len = ft_strlen(*static_buff_ptr) - n_index;
	static_buff_ptr_cpy = ft_strdup(*static_buff_ptr);
	free(*static_buff_ptr);
	*static_buff_ptr = ft_strsub(static_buff_ptr_cpy, n_index + 1, len);
	free(static_buff_ptr_cpy);
	if (!ft_strlen(*static_buff_ptr))
	{
		free(*static_buff_ptr);
		*static_buff_ptr = NULL;
	}
	return (1);
}

static int		do_get_next_line(int fd, char **line)
{
	static t_buff	*static_element;
	int				ret;

	if (!static_element && (static_element = malloc(sizeof(t_buff))))
		static_element->static_buff = NULL;
	if (!static_element)
		return (-1);
	if (!(static_element->static_buff))
		static_element->ret = fill_buffer(fd, &(static_element->static_buff));
	if ((static_element->ret) < 0)
	{
		free(static_element->static_buff);
		(static_element->static_buff) = NULL;
		return ((static_element->ret));
	}
	fill_line(fd, line, &(static_element->static_buff));
	if ((static_element->ret) <= 0)
	{
		if (!(ret = static_element->ret))
			return (0);
		free(static_element);
		static_element = NULL;
	}
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	int		ret;

	if (fd < 0 || line == NULL)
		return (-1);
	ret = do_get_next_line(fd, line);
	return (ret);
}
