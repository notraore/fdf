#ifndef FDF_H
# define FDF_H

#include "./libft/libft.h"

typedef struct		s_tool
{
	int		x;
	int		y;
	int		*img_data;
	void	*mlx;
	void	*win;
	void	*img;
}					t_tool;

/*
** input.c
*/
int		keyboard_input(int keycode);
int		mouse_input(int keycode);

#endif
