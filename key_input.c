/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 18:17:51 by notraore          #+#    #+#             */
/*   Updated: 2017/07/08 18:17:54 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "toolbox.h"

void	clear_and_reput(t_mlx *tool, t_pts pts)
{
	tool->img.img_ptr = mlx_new_image(tool->mlx_ptr, WIDTH, HEIGHT);
	tool->img.img_data = (int *)mlx_get_data_addr(tool->img.img_ptr,
	&tool->img.bpp, &tool->img.sl, &tool->img.end);
	ft_parce_file(tool, pts);
	mlx_put_image_to_window(tool->mlx_ptr, tool->win_ptr, tool->img.img_ptr, 0, 0);
}
int		pressed_key(int keycode, t_mlx *tool)
{
	t_pts pts;
	
	ft_bzero(&pts, sizeof(t_pts));
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	bzero(&tool->img, sizeof(t_img));
	if (keycode == 124)
		tool->m += 5;
	if (keycode == 123)
		tool->m -= 5;
	if (keycode == 69)
		tool->w += 1;
	if (keycode == 78)
		tool->w -= 1;
	if (keycode == 125)
		tool->z += 5;
	if (keycode == 126)
		tool->z -= 5;
	if (keycode == 12)
		tool->mult += 1;
	if (keycode == 14)
		tool->mult -= 1;
	clear_and_reput(tool, pts);
	ft_putstr("Jai bien la key numero ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}

int		mouse_key(int keycode, t_mlx *tool)
{
	(void)tool;
	// void(pts);
	// clear_and_reput(tool, pts);
	ft_putstr("Jai bien la key numero mouse ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}
