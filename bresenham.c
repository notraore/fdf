/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 12:24:07 by notraore          #+#    #+#             */
/*   Updated: 2017/06/14 15:48:17 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "toolbox.h"

void ft_line(int x0, int y0, int x1, int y1, t_mlx *ptr)
{
	t_line horse;

	horse.dx = ABS(x1-x0);
	horse.sx = x0 < x1 ? 1 : -1;
	horse.dy = ABS(y1-y0);
	horse.sy = y0 < y1 ? 1 : -1; 
	horse.err = (horse.dx>horse.dy ? horse.dx : -horse.dy)/2;
	horse.e2 = 0;
	while(i < dx)
	{
		
		if (x0 == x1 && y0 == y1)
			break;
		horse.e2 = horse.err;
		if (horse.e2 >-horse.dx)
		{
			horse.err -= horse.dy;
			x0 += horse.sx;
		}
		if (horse.e2 < horse.dy)
		{
			horse.err += horse.dx;
			y0 += horse.sy;
		}
		i++;
	}
}