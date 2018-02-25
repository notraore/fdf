/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <notraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 18:17:51 by notraore          #+#    #+#             */
/*   Updated: 2018/02/25 22:58:14 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../toolbox.h"

void	clear_and_reput(t_mlx *tl, t_pts *pts)
{
	tl->img.img_ptr = mlx_new_image(tl->mlx, W, H);
	tl->img.dta = (int *)mlx_get_data_addr(tl->img.img_ptr,
	&tl->img.bpp, &tl->img.sl, &tl->img.end);
	ft_fill_tab(tl->stock, tl, pts, tl->taille);
	mlx_put_image_to_window(tl->mlx, tl->win, tl->img.img_ptr, 0, 0);
	mlx_string_put(tl->mlx, tl->win, 15, 15, WHITE, tl->argv);
}

void	tool_clear(t_mlx *ptr)
{
	ptr->up = 0;
	ptr->zoom = 0;
	ptr->z = 0;
	ptr->mlt = 0;
}

void	ft_key_code(int keycode, t_mlx *tool, t_pts *pts)
{
	if (keycode == 2)
		tool->up += 5;
	if (keycode == 0)
		tool->up -= 5;
	if (keycode == 69)
		tool->zoom += 1;
	if (keycode == 78)
		tool->zoom -= 1;
	if (keycode == 1)
		tool->z += 5;
	if (keycode == 13)
		tool->z -= 5;
	if (keycode == 12)
		tool->mlt += 0.17;
	if (keycode == 14)
		tool->mlt -= 0.17;
	if (keycode == 8)
		tool_clear(tool);
	clear_and_reput(tool, pts);
}

int		pressed_key(int keycode, t_mlx *tool)
{
	t_pts pts;

	if (keycode == 53)
		exit(EXIT_SUCCESS);
	ft_bzero(&pts, sizeof(t_pts));
	ft_bzero(&tool->img, sizeof(t_img));
	if (keycode == 2 || keycode == 0 || keycode == 69 || keycode == 78 ||
	keycode == 1 || keycode == 13 || keycode == 12 || keycode == 14
	|| keycode == 8)
		ft_key_code(keycode, tool, &pts);
	return (0);
}
