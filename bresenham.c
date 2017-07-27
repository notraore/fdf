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

/************************************** RELIER DEUX POINTS *********************************************/

void ft_line(long x0, long y0, long x1, long y1, t_mlx *ptr)
{
	t_line line;

	line.dx = labs(x1-x0);
	line.sx = x0 < x1 ? 1 : -1;
	line.dy = labs(y1 - y0);
	line.sy = y0 < y1 ? 1 : -1;
	line.err = (line.dx>line.dy ? line.dx : -line.dy) / 2;
	while(1)
	{
		if (!((x0 - y0) + (y0 + x0) / 2 * WIDTH > WIDTH * HEIGHT) &&
		!((x0 - y0) + (y0 + x0) / 2 * WIDTH < 0))
			ptr->img.img_data[(x0 - y0) + (y0 + x0) / 2 * WIDTH] = ptr->color;
		else
			break;
		if (x0 == x1 && y0 == y1)
			break;
		line.e2 = line.err;
		if (line.e2 >- line.dx)
		{
			line.err -= line.dy;
			x0 += line.sx;
		}
		if (line.e2 < line.dy)
		{
			line.err += line.dx;
			y0 += line.sy;
		}
		// ptr->color += 1;
	}
}

void ft_line2(long x0, long y0, long x1, long y1, t_mlx *ptr)
{
	t_line line;

	line.dx = labs(x1-x0);
	line.sx = x0 < x1 ? 1 : -1;
	line.dy = labs(y1 - y0);
	line.sy = y0 < y1 ? 1 : -1;
	line.err = (line.dx>line.dy ? line.dx : -line.dy) / 2;
	while(1)
	{
		if (!((x0 - y0) + (y0 + x0 - ptr->y)/ 2 * WIDTH > WIDTH * HEIGHT) &&
		!((x0 - y0) + (y0 + x0 - ptr->y)/ 2 * WIDTH < 0))
			ptr->img.img_data[(x0 - y0) + (y0 + x0 - ptr->y)/ 2 * WIDTH] = ptr->color;
		else
			break;
		if (x0 == x1 && y0 == y1)
			break;
		line.e2 = line.err;
		if (line.e2 >- line.dx)
		{
			line.err -= line.dy;
			x0 += line.sx;
		}
		if (line.e2 < line.dy)
		{
			line.err += line.dx;
			y0 += line.sy;
		}
		// ptr->color += 1;
	}
}
