/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelloun <nbelloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 09:56:11 by nbelloun          #+#    #+#             */
/*   Updated: 2014/11/29 13:58:57 by nbelloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define BUFF_SIZE 26

int					get_next_line(int const fd, char **line);

typedef struct		s_buff
{
	int				ret;
	char			*static_buff;
}					t_buff;

#endif
