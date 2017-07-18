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

void		ft_fill_tab(int **sck, t_mlx *ptr, t_pts pts, int *taille)
{
	ft_bzero(&pts, (sizeof(t_pts)));
	while (sck[pts.j] && sck[pts.j] + 1 != NULL)
	{
		pts.x = 10;
		pts.i = 0;
		while (pts.i < taille[pts.j])
		{
			pts.next_x = (pts.x + LEN) - (sck[pts.j][pts.i + 1] * 2);
			pts.next_y = pts.y - (sck[pts.j][pts.i + 1] * 2);
			ptr->color  = (sck[pts.j][pts.i] == 0 && (pts.next_x == pts.x + LEN)) ? BLUE : RED;
			if (pts.i != taille[pts.j] - 1)
				ft_line(pts.x - (sck[pts.j][pts.i] * 2) , pts.y - (sck[pts.j][pts.i] * 2), pts.next_x, pts.next_y , ptr);
			if  (pts.j > 1 && sck[pts.j - 1][pts.i] != 0)
			{
				ptr->y = (sck[pts.j][pts.i] == 0) ? (sck[pts.j - 1][pts.i] * 4)/2 : (sck[pts.j - 1][pts.i] * 4);
				if (sck[pts.j][pts.i] == 0 && (ptr->color = RED))
					ft_line(pts.x , pts.y , pts.x - ptr->y, pts.y - LEN -(sck[pts.j -1][pts.i] * 2) , ptr);
				if (sck[pts.j][pts.i] != 0)
					ft_line2(pts.x , pts.y, pts.x, pts.y - LEN, ptr);
			}
			else if (pts.j > 0 && ((sck[pts.j][pts.i] == 0 && (ptr->color = BLUE)) || sck[pts.j][pts.i] != 0))
				ft_line(pts.x - (sck[pts.j][pts.i] * 2) , pts.y - (sck[pts.j][pts.i] * 2), pts.x, pts.y - LEN , ptr);
			pts.x += LEN;
			pts.i += 1;
		}
		pts.y += LEN;
		pts.j += 1;
	}
}

void		ft_parce_file(int fd, char *argv, t_mlx *ptr, t_pts pts)
{
	t_pce	pce;
	ft_bzero(&pce, (sizeof(t_pce)));
	(!(fd = open(argv, O_RDONLY)) ? exit(-1) : 0);
	while ((pce.value = get_next_line(fd, &pce.line)) == 1)
		pce.i++;
	close(fd);
	(!(fd = open(argv, O_RDONLY)) ? exit(-1) : 0);
	pce.stock = (int **)ft_memalloc(sizeof(int *) * pce.i + 1);
	pce.taille = (int *) ft_memalloc(sizeof(int) * pce.i + 1);
	pce.i = 0;
	while ((pce.value = get_next_line(fd, &pce.line)) == 1)
	{
		pce.tmp = ft_strsplit(pce.line, ' ');
		while(pce.tmp[pce.i])
			pce.i++;
		pce.stock[pce.j] = ft_memalloc(sizeof(int) * pce.i + 1);
		pce.i = -1;
		while(pce.tmp[++pce.i])
			pce.stock[pce.j][pce.i] = ft_atoi(pce.tmp[pce.i]);
		pce.taille[pce.j] = pce.i;
		free(pce.tmp);
		pce.j++;
	}
	pce.stock[pce.j] = NULL;
	ft_fill_tab(pce.stock, ptr, pts, pce.taille);
	free(pce.stock);
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
