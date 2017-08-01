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

/*
**Fonction cut de remplissage de l'image data en iso
*/

void		ft_norme(int **sck, t_pts pts, t_mlx *ptr)
{
	if (pts.j >= 1 && sck[pts.j - 1][pts.i] != 0)
	{
		ptr->y = (sck[pts.j][pts.i] == 0) ? ((sck[pts.j - 1][pts.i])
		* ptr->mlt * 2) / 2 : ((sck[pts.j - 1][pts.i]) * ptr->mlt * 2);
		if (sck[pts.j][pts.i] == 0 && (ptr->clr = BLUE))
			ft_line((pts.x + ptr->up) + ((sck[pts.j][pts.i]) * ptr->mlt),
			(pts.y + ptr->z) + ((sck[pts.j][pts.i]) * ptr->mlt),
			(pts.x + ptr->up) - ptr->y, (pts.y + ptr->z) - (LEN + ptr->zoom)
			- (sck[pts.j - 1][pts.i]) * ptr->mlt, ptr);
		if (sck[pts.j][pts.i] != 0)
			ft_line2((pts.x + ptr->up), (pts.y + ptr->z) - (LEN + ptr->zoom),
			(pts.x + ptr->up) + (sck[pts.j - 1][pts.i] -
			(sck[pts.j][pts.i])) * ptr->mlt,
			(pts.y + ptr->z) + (sck[pts.j - 1][pts.i] -
			(sck[pts.j][pts.i])) * ptr->mlt, ptr);
	}
	else if (pts.j > 0 && ((sck[pts.j][pts.i] == 0 &&
	(ptr->clr = RED)) || sck[pts.j][pts.i] != 0))
		ft_line((ptr->up + pts.x) - ((sck[pts.j][pts.i]) * ptr->mlt),
		(pts.y + ptr->z) - ((sck[pts.j][pts.i]) * ptr->mlt), (pts.x + ptr->up),
		(pts.y + ptr->z) - (LEN + ptr->zoom), ptr);
}

/*
**Fonction de remplissage, elle recupere le
**tableau de coordonees et fill l'image data en iso avec la formule :
**X = X - Y;
**Y = (X + Y) / 2;
**Elle trace un trait entre le point de depart au point actuel (pce.i) au
**point a la meme position au dessus (pce.j - 1) en s'adaptant a la auteur
**du point trouve; plus le numero est haut, plus haut sera le point de liaison.
*/

void		ft_fill_tab(int **sck, t_mlx *ptr, t_pts pts, int *taille)
{
	ft_bzero(&pts, (sizeof(t_pts)));
	while (sck[pts.j] && sck[pts.j] + 1 != NULL)
	{
		pts.x = 400;
		pts.i = 0;
		while (pts.i < taille[pts.j])
		{
			pts.next_x = (pts.x + (LEN + ptr->zoom)) -
			((sck[pts.j][pts.i + 1]) * ptr->mlt);
			pts.next_y = pts.y - ((sck[pts.j][pts.i + 1]) * ptr->mlt);
			ptr->clr = (sck[pts.j][pts.i] == 0 && (pts.next_x ==
			pts.x + (LEN + ptr->zoom))) ? RED : BLUE;
			if (pts.i != taille[pts.j] - 1)
				ft_line((pts.x + ptr->up) - ((sck[pts.j][pts.i]) * ptr->mlt),
				(pts.y + ptr->z) - ((sck[pts.j][pts.i]) * ptr->mlt),
				pts.next_x + ptr->up, (ptr->z + pts.next_y), ptr);
			ft_norme(sck, pts, ptr);
			pts.x += (LEN + ptr->zoom);
			pts.i += 1;
		}
		pts.y += (LEN + ptr->zoom);
		pts.j += 1;
	}
}

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

void		ft_parce_file(t_mlx *ptr, t_pts pts)
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
		while (pce.tmp[pce.i])
			pce.i += 1;
		ptr->stock[pce.j] = ft_memalloc(sizeof(int) * pce.i + 1);
		pce.i = 0;
		while (pce.tmp[pce.i += 1])
			ptr->stock[pce.j][pce.i] = ft_atoi(pce.tmp[pce.i]);
		ptr->taille[pce.j] = pce.i;
		free(pce.tmp);
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
	ft_parce_file(ptr, pts);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.img_ptr, 0, 0);
	mlx_string_put(ptr->mlx, ptr->win, 15, 15, WHITE, ptr->argv);
	mlx_destroy_image(ptr->mlx, ptr->img.dta);
	mlx_hook(ptr->win, 2, (1L << 0), pressed_key, ptr);
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
