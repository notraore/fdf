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

long		ft_point_save(int flag, long x, long y, int high)
{
	if (flag == 1)
		return (x - y);
	if (flag == 2)
		return ((y + x - high * 5) / 2 * WIDTH);
	return (0);
}

void		ft_fill_tab(int **stock, t_mlx *ptr, t_pts pts, int *taille)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (stock[j])
	{
		printf("j = %d\n", j);
		pts.x = 502;
		i = 0;
		while (i < taille[j])
		{
			printf("i = %d\n", i);
			if (stock[j][i] == 0)
			{
				ptr->img.img_data[(pts.x - pts.y) + (pts.y + pts.x) / 2 * WIDTH] = GREEN;
				ft_line(pts.x, pts.y, pts.x - LEN, pts.y, ptr);
				ft_line(pts.x, pts.y, pts.x, pts.y - LEN, ptr);
				pts.x += LEN;
			}
			else
			{
				ptr->img.img_data[(pts.x - pts.y) + (pts.y + pts.x - stock[j][i] * 4) / 2 * WIDTH] = RED;
				ft_line2(pts.x - stock[j][i] * 4, pts.y - stock[j][i] * 4, pts.x - LEN, pts.y, ptr);
				ft_line2(pts.x  - stock[j][i] * 4, pts.y - stock[j][i] * 4, pts.x, pts.y - LEN, ptr);
				pts.x += LEN;
			}
			i++;
		}
		pts.y += LEN;
		j++;
	}
}

// void		ft_array_to_int_tab(char *tmp, int **stock)
{
		while(tmp[i])
			i++;
		stock[j] = ft_memalloc(sizeof(int) * i + 1);
		i = -1;
		while(tmp[++i])
			stock[j][i] = ft_atoi(tmp[i]);
}

void		ft_parce_file(int fd, char *argv, t_mlx *ptr, t_pts pts)
{
	int			value;
	char		*line;
	int			**stock;
	int 		*taille;
	char		**tmp;
	int 		i;
	int			j; 
	
	j = 0;
	i = 0;
	pts.x = 502;
	pts.y = 25;
	(!(fd = open(argv, O_RDONLY)) ? exit(-1) : 0);
	while ((value = get_next_line(fd, &line)) == 1)
		i++;
	close(fd);
	(!(fd = open(argv, O_RDONLY)) ? exit(-1) : 0);
	stock = (int **)ft_memalloc(sizeof(int *) * i + 1);
	taille = (int *) ft_memalloc(sizeof(int) * i + 1);
	i = 0;
	while ((value = get_next_line(fd, &line)) == 1)
	{
		tmp = ft_strsplit(line, ' ');
		while(tmp[i])
			i++;
		stock[j] = ft_memalloc(sizeof(int) * i + 1);
		i = -1;
		while(tmp[++i])
			stock[j][i] = ft_atoi(tmp[i]);
		taille[j] = i;
		free(tmp);
		j++;
	}
	ft_fill_tab(stock, ptr, pts, taille);
	free(stock);
}

void		ft_create_win(int fd, char *argv, t_mlx *ptr)
{
	t_pts pts;

	pts.x = 0;
	pts.y = 0;
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, WIDTH, HEIGHT, "FDF 1280x720");
	ptr->img.img_ptr = mlx_new_image(ptr->mlx_ptr, WIDTH, HEIGHT);
	ptr->img.img_data = (int *)mlx_get_data_addr(ptr->img.img_ptr,
	&ptr->img.bpp, &ptr->img.sl, &ptr->img.end);
	ft_parce_file(fd, argv, ptr, pts);
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
	tool = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	ft_create_win(fd, argv[1], tool);
	free(tool);
	return (0);
}
