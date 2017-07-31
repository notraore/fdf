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

void	clear_and_reput(t_mlx *tl, t_pts pts)
{
	tl->img.img_ptr = mlx_new_image(tl->mlx_ptr, WIDTH, HEIGHT);
	tl->img.img_data = (int *)mlx_get_data_addr(tl->img.img_ptr,
	&tl->img.bpp, &tl->img.sl, &tl->img.end);
	ft_parce_file(tl, pts);
	mlx_put_image_to_window(tl->mlx_ptr, tl->win_ptr, tl->img.img_ptr, 0, 0);
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
		tool->z += 3;
	if (keycode == 126)
		tool->z -= 3;
	if (keycode == 12)
		tool->mult += 0.16;
	if (keycode == 14)
		tool->mult -= 0.16;
	clear_and_reput(tool, pts);
	return (0);
}
