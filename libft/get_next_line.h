/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:57:03 by notraore          #+#    #+#             */
/*   Updated: 2017/05/24 12:59:17 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H
# define BUFF_SIZE 888
# include "libft.h"

typedef struct		s_stock
{
	int				ret;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	char			*save;
	char			*rest;
}					t_stock;

int					get_next_line(int const fd, char **line);

#endif
