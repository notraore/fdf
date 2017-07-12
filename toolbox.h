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
# include "./libft/libft.h"
# include "./minilibx/mlx.h"

# define ABS(Value) (Value < 0 ? (-Value) : (Value))

# define WIDTH 900
# define HEIGHT 900
# define LEN 50

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

#endif
