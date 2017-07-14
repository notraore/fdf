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

void ft_line(int x0, int y0, int x1, int y1, void *mlx, void *win)
{

	int dx = ABS(x1-x0);
	int sx = x0 < x1 ? 1 : -1;
	int dy = ABS(y1-y0);
	int sy = y0 < y1 ? 1 : -1; 
	int err = (dx>dy ? dx : -dy)/2;
	int e2 = 0;
	while(1)
	{
		mlx_pixel_put(mlx, win, x0, y0, 0xFFFFFF);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = err;
		if (e2 >-dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}

// int main(int argc, char const *argv[])
// {
// 	void *mlx = mlx_init();
// 	void *win = mlx_new_window(mlx, WIDTH, HEIGHT, "FDF 1280x720");

// 	ft_line(19, 19, 699, 59, mlx, win);
// 	mlx_loop(mlx);
// 	return 0;
// }