/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 19:08:45 by notraore          #+#    #+#             */
/*   Updated: 2017/08/03 19:08:53 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/toolbox.h"

void	ft_solving(int **sck, t_pts *pts, t_mlx *ptr)
{
	pts->x0 = (pts->x + ptr->up) + ((sck[pts->j][pts->i]) * ptr->mlt);
	pts->y0 = (pts->y + ptr->z) + ((sck[pts->j][pts->i]) * ptr->mlt);
	pts->x1 = (pts->x + ptr->up) - ptr->y;
	pts->y1 = (pts->y + ptr->z) - (LEN + ptr->zoom) -
	(sck[pts->j - 1][pts->i]) * ptr->mlt;
}

void	ft_solving2(int **sck, t_pts *pts, t_mlx *ptr)
{
	pts->x0 = (pts->x + ptr->up);
	pts->y0 = (pts->y + ptr->z) - (LEN + ptr->zoom);
	pts->x1 = (pts->x + ptr->up) + (sck[pts->j - 1][pts->i] -
	(sck[pts->j][pts->i])) * ptr->mlt;
	pts->y1 = (pts->y + ptr->z) + (sck[pts->j - 1][pts->i] -
	(sck[pts->j][pts->i])) * ptr->mlt;
}

void	ft_solving3(int **sck, t_pts *pts, t_mlx *ptr)
{
	pts->x0 = (ptr->up + pts->x) - ((sck[pts->j][pts->i]) * ptr->mlt);
	pts->y0 = (pts->y + ptr->z) - ((sck[pts->j][pts->i]) * ptr->mlt);
	pts->x1 = (pts->x + ptr->up);
	pts->y1 = (pts->y + ptr->z) - (LEN + ptr->zoom);
}

void	ft_solving4(int **sck, t_pts *pts, t_mlx *ptr)
{
	pts->x0 = (pts->x + ptr->up) - ((sck[pts->j][pts->i]) * ptr->mlt);
	pts->y0 = (pts->y + ptr->z) - ((sck[pts->j][pts->i]) * ptr->mlt);
	pts->x1 = pts->next_x + ptr->up;
	pts->y1 = (ptr->z + pts->next_y);
}
