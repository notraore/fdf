/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 17:23:26 by notraore          #+#    #+#             */
/*   Updated: 2017/08/02 17:23:27 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "toolbox.h"

/*
**Fonction cut de remplissage de l'image data en iso
*/

void		ft_norme(int **sck, t_pts *pts, t_mlx *ptr)
{
	if (pts->j >= 1 && sck[pts->j - 1][pts->i] != 0)
	{
		ptr->y = (sck[pts->j][pts->i] == 0) ? ((sck[pts->j - 1][pts->i])
		* ptr->mlt * 2) / 2 : ((sck[pts->j - 1][pts->i]) * ptr->mlt * 2);
		if (sck[pts->j][pts->i] == 0 && (ptr->clr = BLUE))
			ft_line((pts->x + ptr->up) + ((sck[pts->j][pts->i]) * ptr->mlt),
			(pts->y + ptr->z) + ((sck[pts->j][pts->i]) * ptr->mlt),
			(pts->x + ptr->up) - ptr->y, (pts->y + ptr->z) - (LEN + ptr->zoom)
			- (sck[pts->j - 1][pts->i]) * ptr->mlt, ptr);
		if (sck[pts->j][pts->i] != 0)
			ft_line(((pts->x / 2) + ptr->up), (pts->y + ptr->z) - (LEN + ptr->zoom),
			((pts->x / 2) + ptr->up) + (sck[pts->j - 1][pts->i] -
			(sck[pts->j][pts->i])) * ptr->mlt,
			(pts->y + ptr->z) + (sck[pts->j - 1][pts->i] -
			(sck[pts->j][pts->i])) * ptr->mlt, ptr);
	}
	else if (pts->j > 0 && ((sck[pts->j][pts->i] == 0 &&
	(ptr->clr = RED)) || sck[pts->j][pts->i] != 0))
		ft_line((ptr->up + pts->x) - ((sck[pts->j][pts->i]) * ptr->mlt),
		(pts->y + ptr->z) - ((sck[pts->j][pts->i]) * ptr->mlt),
		(pts->x + ptr->up), (pts->y + ptr->z) - (LEN + ptr->zoom), ptr);
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

void		ft_fill_tab(int **sck, t_mlx *ptr, t_pts *pts, int *taille)
{
	while (sck[pts->j] && sck[pts->j] + 1 != NULL)
	{
		pts->x = 400;
		pts->i = 0;
		while (pts->i < taille[pts->j])
		{
			pts->next_x = (pts->x + (LEN + ptr->zoom)) -
			((sck[pts->j][pts->i + 1]) * ptr->mlt);
			pts->next_y = pts->y - ((sck[pts->j][pts->i + 1]) * ptr->mlt);
			ptr->clr = (sck[pts->j][pts->i] == 0 && (pts->next_x ==
			pts->x + (LEN + ptr->zoom))) ? RED : BLUE;
			if (pts->i != taille[pts->j] - 1)
				ft_line((pts->x + ptr->up) - ((sck[pts->j][pts->i]) * ptr->mlt),
				(pts->y + ptr->z) - ((sck[pts->j][pts->i]) * ptr->mlt),
				pts->next_x + ptr->up, (ptr->z + pts->next_y), ptr);
			ft_norme(sck, pts, ptr);
			pts->x += (LEN + ptr->zoom);
			pts->i += 1;
		}
		pts->y += (LEN + ptr->zoom);
		pts->j += 1;
	}
}
