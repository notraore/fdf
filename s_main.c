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

int		**ft_atoi_cpy(int **dest, char **src)
{
	int i;
	int j;

	while (src[j][i])
	{
		while (src[i])
		{
			dest[j][i] = ft_atoi(src[i]);
			i++;
		}
		j++;
	}
	return (dest);
}


int		ft_parce_file(int fd, char *argv, t_mlx *ptr)
{
	int			**tab;
	int			value;
	int			count;
	char		*line;
	int			j = 0;
	char		**stock;

	count = 0;
	(!(fd = open(argv, O_RDONLY)) ? exit(-1) : 0);
	while ((value = get_next_line(fd, &line)) == 1)
		count++;
	close(fd);
	tab = (int **)ft_memalloc(sizeof(int *) * count);
	(!(fd = open(argv, O_RDONLY)) ? exit(-1) : 0);
	int i = 0;
	while((value= get_next_line(fd, &line)) == 1)
	{
		stock = ft_strsplit(line, ' ');
		while (stock[i])
		{
			printf("[%s]", stock[i++]);

		}
		printf("\n");
		i = 0;
	}
	return (0);
}

void	ft_create_win(t_mlx *ptr)
{
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, WIDTH, HEIGHT, "FDF 1920x1080");
	ptr->img.img_ptr = mlx_new_image(ptr->mlx_ptr, WIDTH, HEIGHT);
	ptr->img.img_data = (int *)mlx_get_data_addr(ptr->img.img_ptr,
	&ptr->img.bpp, &ptr->img.sl, &ptr->img.end);
	ptr->img.img_data[99 + WIDTH * 60] = 0x00FFFF;
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img.img_ptr, 0, 0);
	mlx_key_hook(ptr->win_ptr, pressed_key, ptr);
	mlx_mouse_hook(ptr->win_ptr, mouse_key, 0);
	mlx_loop(ptr->mlx_ptr);
}

int		main(int argc, char **argv)
{
	int			fd;
	char		**parce;
	t_mlx		*tool;

	tool = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	ft_parce_file(fd, argv[1]);
	ft_create_win(tool);
	return (0);
}
