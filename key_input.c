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

int		pressed_key(int keycode, t_mlx *tool)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 124)
	{
		mlx_destroy_image(tool->mlx_ptr, tool->img.img_data);
		bzero(&tool->img, sizeof(t_mlx));
		tool->img.img_ptr = mlx_new_image(tool->mlx_ptr, WIDTH, HEIGHT);
		tool->img.img_data = (int *)mlx_get_data_addr(tool->img.img_ptr,
		&tool->img.bpp, &tool->img.sl, &tool->img.end);
		tool->x += 15;
		mlx_put_image_to_window(tool->mlx_ptr, tool->win_ptr, tool->img.img_ptr, 0, 0);
	}
	if (keycode  == 15)
	{
		printf("error at line %d\n", __LINE__);
	}
	ft_putstr("Jai bien la key numero ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}

int		mouse_key(int keycode)//, t_mlx *ptr)
{
	ft_putstr("Jai bien la key numero mouse ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}
