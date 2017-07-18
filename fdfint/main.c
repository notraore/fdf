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

// ptr->img.img_data[(pts.x - pts.y) + (pts.y + pts.x - stock[j][i] * 4) / 2 * WIDTH] = GREEN;

#include "toolbox.h"

void		ft_fill_tab(int **stock, t_mlx *ptr, t_pts pts, int *taille)
{
	int i;
	int j;
	int next_x;
	int next_y;
	int prev_x;
	int prev_y;

	i = 0;
	j = 0;
	prev_y = 0;
	prev_x = 0;
	while (stock[j] && stock[j] + 1 != NULL)
	{
		pts.x = 502;
		i = 0;
		while (i < taille[j])
		{
			next_x = (pts.x + LEN) - (stock[j][i + 1] * 2);
			next_y = pts.y - (stock[j][i + 1] * 2);
			if (i != taille[j] - 1)
				next_y = pts.y - (stock[j][i + 1] * 4) / 2;
			if (stock[j][i] == 0 && !(i != taille[j] - 1 && stock[j][i + 1] != 0))
				ptr->color = WHITE;
			else
				ptr->color = RED;
			if (i != taille[j] - 1)
				ft_line(pts.x - (stock[j][i] * 2) , pts.y - (stock[j][i] * 2), next_x, next_y , ptr);
			if  (j > 1 && stock[j - 1][i] != 0)
			{
				ptr->y =  (stock[j - 1][i] * 4);
				if (stock[j][i] == 0)
				{
					ptr->color = RED;
					ptr->y =  (stock[j - 1][i] * 4);
					ft_line(pts.x , pts.y , pts.x - 100, pts.y - LEN, ptr);
				}
				//if (stock[j][i] != 0)
					//ft_line2(pts.x , pts.y, pts.x, pts.y - LEN, ptr);
			}
			//else if (j > 0 )
				//ft_line(pts.x - (stock[j][i] * 2) , pts.y - (stock[j][i] * 2), pts.x, pts.y- LEN, ptr);
			pts.x += LEN;
			i++;
		}
		pts.y += LEN;
		j++;
	}
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
	stock[j] = NULL;
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
