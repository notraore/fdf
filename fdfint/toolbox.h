/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 20:42:23 by notraore          #+#    #+#             */
/*   Updated: 2017/07/08 20:42:26 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TOOLBOX_H
# define __TOOLBOX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "./libft/libft.h"
# include "./minilibx/mlx.h"

# define WIDTH 1280
# define HEIGHT 720
# define LEN 25
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

typedef struct		s_pts
{
	int 			x;
	int 			y;
	int 			z;
	int				color;
}					t_pts;

typedef struct		s_line
{
	int				dx;
	int				sx;
	int				dy;
	int				sy; 
	int				err;
	int				e2;
}					t_line;

typedef struct		s_img
{
	int				sl;
	int				bpp;
	int				end;

	void			*img_ptr;
	int				*img_data;
}					t_img;

typedef struct		s_mlx
{
	int				x;
	int				y;
	int				color;
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
}					t_mlx;

/*
**PRESSED_KEY
*/

int					pressed_key(int keycode, t_mlx *tool);
int					mouse_key(int keycode);
/*
**error
*/
void				ft_print_err(int argc);
/*
**bresenham
*/
void ft_line(long x0, long y0, long x1, long y1, t_mlx *ptr);
void ft_line2(long x0, long y0, long x1, long y1, t_mlx *ptr);

#endif
