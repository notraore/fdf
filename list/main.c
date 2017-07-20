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

size_t		ft_lstsize(t_lst *list)
{
	size_t i;

	i = 0;
	if (list)
		while (list != NULL)
		{
			list = list->next;
			i++;
		}
	return (i);
}

void		ft_fill_tab(t_mlx *ptr, t_pts pts, t_lst *line, int size)
{
	t_lst *tmp;
	t_lst *tmprev;

	tmp = line;
	tmprev = NULL;
	ft_bzero(&pts, (sizeof(t_pts)));
	while (tmp->next)
	{
		pts.x = 200;
		pts.i = 0;
		while (pts.i < size)
		{
			printf("lol\n");
			pts.next_x = (pts.x + LEN) - (ft_atoi(tmp->stc[pts.i + 1]) * 2);
			pts.next_y = pts.y - (ft_atoi(tmp->stc[pts.i + 1]) * 2);
			printf("nextx = %d nexty = %d\npts.x = %d pts.y = %d\n", pts.next_x, pts.next_y, pts.x, pts.y);
			ptr->color = (ft_atoi(tmp->stc[pts.i]) == 0 && (pts.next_x ==
			pts.x + LEN)) ? BLUE : GREEN;
			if (pts.i != size - 1)
				ft_line(pts.x - (ft_atoi(tmp->stc[pts.i]) * 2), pts.y -
				(ft_atoi(tmp->stc[pts.i]) * 2), pts.next_x, pts.next_y, ptr);
			if (tmprev && ft_atoi(tmprev->stc[pts.i]) != 0)
			{
				ptr->y = (ft_atoi(tmp->stc[pts.i]) == 0) ? (ft_atoi(tmprev->stc[pts.i]) * 4) / 2
				: (ft_atoi(tmprev->stc[pts.i]) * 4);
				if (ft_atoi(tmp->stc[pts.i]) == 0 && (ptr->color = GREEN))
					ft_line(pts.x + (ft_atoi(tmp->stc[pts.i]) * 2), pts.y +
					(ft_atoi(tmp->stc[pts.i]) * 2), pts.x - ptr->y, pts.y - LEN
					- (ft_atoi(tmprev->stc[pts.i]) * 2), ptr);
				if (ft_atoi(tmp->stc[pts.i]) != 0)
					ft_line2(pts.x, pts.y - LEN, pts.x +
						(ft_atoi(tmprev->stc[pts.i]) - (ft_atoi(tmp->stc[pts.i]))) * 2,
						pts.y + (ft_atoi(tmprev->stc[pts.i]) -
						(ft_atoi(tmp->stc[pts.i]))) * 2, ptr);
			}
			else if (pts.j > 0 && ((ft_atoi(tmp->stc[pts.i]) == 0 &&
			(ptr->color = BLUE)) || ft_atoi(tmp->stc[pts.i]) != 0))
				ft_line(pts.x - (ft_atoi(tmp->stc[pts.i]) * 2), pts.y
						- (ft_atoi(tmp->stc[pts.i]) * 2), pts.x, pts.y - LEN
						, ptr);
			pts.x += LEN;
			pts.i += 1;
		}
		pts.y += LEN;
		tmprev = tmp;
		tmp = tmp->next;
	}
}

void		ft_parce_file(char *argv, t_mlx *ptr, t_pts pts, t_lst *lines)
{
	int size;
	t_pce	pce;
	t_lst	*tmp;
	int i = 0;
	tmp = lines;
	size = 0;
	ft_bzero(&pce, (sizeof(t_pce)));
	(!(ptr->fd = open(argv, O_RDONLY)) ? exit(-1) : 0);
	pce.i = 0;
	while ((pce.value = get_next_line(ptr->fd, &pce.line)) == 1)
	{
		i = 0;
		tmp->stc = ft_strsplit(pce.line, ' ');
		while (tmp->stc[i])
		{
			printf("%d  ", ft_atoi(tmp->stc[i]));
			i++;
		}
		printf("\n");
		tmp->next = (t_lst *)ft_memalloc(sizeof(t_lst));
		tmp = tmp->next;
		// pce.tmp = ft_strsplit(pce.line, ' ');
		// while (pce.tmp[pce.i])
			// pce.i += 1;
		// pce.stc[pce.j] = ft_memalloc(sizeof(int) * pce.i + 1);
		// pce.i = 0;
		// while (pce.tmp[pce.i += 1])
			// pce.stc[pce.j][pce.i] = ft_atoi(pce.tmp[pce.i]);
		// pce.taille[pce.j] = pce.i;
		// free(pce.tmp);
		// pce.j += 1;
	}
	tmp->stc = NULL;
	tmp->next = NULL;
	tmp = lines;
	size = ft_lstsize(lines);
	printf("size = %d\n",size );
	ft_fill_tab(ptr, pts, tmp, size);
}

void		ft_create_win(char *argv, t_mlx *ptr, t_lst *lines)
{
	t_pts pts;

	ft_bzero(&pts, sizeof(t_pts));
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, WIDTH, HEIGHT, "FDF 1280x720");
	ptr->img.img_ptr = mlx_new_image(ptr->mlx_ptr, WIDTH, HEIGHT);
	ptr->img.img_data = (int *)mlx_get_data_addr(ptr->img.img_ptr,
	&ptr->img.bpp, &ptr->img.sl, &ptr->img.end);
	ft_parce_file(argv, ptr, pts, lines);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img.img_ptr, 0, 0);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img.img_data);
	mlx_key_hook(ptr->win_ptr, pressed_key, ptr);
	mlx_mouse_hook(ptr->win_ptr, mouse_key, 0);
	mlx_loop(ptr->mlx_ptr);
}

int			main(int argc, char **argv)
{
	int			fd;
	t_mlx		*tool;
	t_lst		*lines;

	if (argc != 2)
		ft_print_err(argc);
	fd = 0;
	tool = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	lines = (t_lst *)ft_memalloc(sizeof(t_lst));
	ft_create_win(argv[1], tool, lines);
	free(tool);
	return (0);
}
