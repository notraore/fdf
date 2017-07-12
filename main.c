/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:37:22 by notraore          #+#    #+#             */
/*   Updated: 2017/07/03 19:33:50 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "toolbox.h"

void		ft_fill_tab(char **stock, t_mlx *ptr, int x, int y)
{
	int i;
	int color;

	i = 0;
	color = 0xFFA050;
	while (stock[i])
	{
		if (ft_atoi(stock[i]) == 0)
		{
			ptr->img.img_data[(x - y) + (y + x) / 2 * WIDTH] = BLUE;
			x += LEN;
		}
		if (ft_atoi(stock[i]) != 0)
		{
			ptr->img.img_data[(x - y) + (y + x - ft_atoi(stock[i]) * 5) / 2 * WIDTH] = 0xFE2EC8;
			x += LEN;
			color++;
		}
		i++;
	}
}

void		ft_parce_file(int fd, char *argv, t_mlx *ptr)
{
	int			x;
	int			y;
	int			value;
	char		*line;
	char		**stock;

	x = 700;
	y = 0;
	(!(fd = open(argv, O_RDONLY)) ? exit(-1) : 0);
	while ((value = get_next_line(fd, &line)) == 1)
	{
		stock = ft_strsplit(line, ' ');
		ft_fill_tab(stock, ptr, x, y);
		y += LEN;
	}
}

void		ft_create_win(int fd, char *argv, t_mlx *ptr)
{
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, WIDTH, HEIGHT, "FDF 1920x1080");
	ptr->img.img_ptr = mlx_new_image(ptr->mlx_ptr, WIDTH, HEIGHT);
	ptr->img.img_data = (int *)mlx_get_data_addr(ptr->img.img_ptr,
	&ptr->img.bpp, &ptr->img.sl, &ptr->img.end);
	ft_parce_file(fd, argv, ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img.img_ptr, 0, 0);
	mlx_key_hook(ptr->win_ptr, pressed_key, ptr);
	mlx_mouse_hook(ptr->win_ptr, mouse_key, 0);
	mlx_loop(ptr->mlx_ptr);
}

int			main(int argc, char **argv)
{
	int			fd;
	t_mlx		*tool;

	if (argc != 2)
		ft_print_err(argc);
	fd = 0;
	(void)argc;
	tool = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	ft_create_win(fd, argv[1], tool);
	free(tool);
	return (0);
}
