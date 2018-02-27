/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:37:22 by notraore          #+#    #+#             */
/*   Updated: 2017/08/03 19:33:15 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/toolbox.h"

int			open_close_fd(int fd, char *argv, t_pce *pce)
{
	int i;

	pce->line = NULL;
	i = 0;
	(!(fd = open(argv, O_RDONLY)) ? exit(-1) : 0);
	while ((pce->value = get_next_line(fd, &pce->line)) == 1)
	{
		if (pce->line)
		{
			free(pce->line);
			pce->line = NULL;
		}
		i++;
	}
	if (pce->line)
	{
		free(pce->line);
		pce->line = NULL;
	}
	close(fd);
	return (i);
}

void		ft_parce_file(t_mlx *ptr, t_pts *pts)
{
	t_pce	pce;

	ft_bzero(&pce, (sizeof(t_pce)));
	pce.i = open_close_fd(ptr->fd, ptr->argv, &pce);
	(!(ptr->fd = open(ptr->argv, O_RDONLY)) ? exit(-1) : 0);
	ptr->stock = (int **)ft_memalloc(sizeof(int *) * pce.i + 1);
	ptr->taille = (int *)ft_memalloc(sizeof(int) * pce.i + 1);
	pce.i = 0;
	while ((pce.value = get_next_line(ptr->fd, &pce.line)) == 1)
	{
		pce.tmp = ft_strsplit(pce.line, ' ');
		while (pce.tmp[pce.i++])
			pce.i += 1;
		ptr->stock[pce.j] = ft_memalloc(sizeof(int) * pce.i + 1);
		pce.i = -1;
		while (pce.tmp[pce.i += 1])
			ptr->stock[pce.j][pce.i] = ft_atoi(pce.tmp[pce.i]);
		ptr->taille[pce.j] = pce.i;
		free_tab(pce.tmp);
		free(pce.line);
		pce.j += 1;
	}
	ptr->stock[pce.j] = NULL;
	ft_fill_tab(ptr->stock, ptr, pts, ptr->taille);
}

void		ft_create_win(char *av, t_mlx *ptr)
{
	t_pts pts;

	ft_bzero(&pts, sizeof(t_pts));
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, W, H, av);
	ptr->img.img_ptr = mlx_new_image(ptr->mlx, W, H);
	ptr->img.dta = (int *)mlx_get_data_addr(ptr->img.img_ptr,
	&ptr->img.bpp, &ptr->img.sl, &ptr->img.end);
	ptr->argv = av;
	ft_parce_file(ptr, &pts);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.img_ptr, 0, 0);
	mlx_string_put(ptr->mlx, ptr->win, 15, 15, WHITE,
	"Welcome to FDF project!");
	mlx_destroy_image(ptr->mlx, ptr->img.dta);
	mlx_hook(ptr->win, 2, (1L << 0), &pressed_key, ptr);
	mlx_loop(ptr->mlx);
}

int			main(int argc, char **argv)
{
	int			fd;
	t_mlx		*tool;

	if (argc != 2)
		ft_print_err(argc);
	if (ft_strcmp(argv[1], "help") == 0)
		ft_help();
	fd = 0;
	tool = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	ft_create_win(argv[1], tool);
	free(tool);
	return (0);
}
