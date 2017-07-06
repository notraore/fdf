#ifndef FDF_H
# define FDF_H

#include "./libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# define WIDTH 1920
# define HEIGHT 1080

/*
**Structure des varialbes de la minilibX;
*/
typedef struct		s_tool
{
	int				x;
	int				y;
	int				sl;
	int				color;
	int				bpp;
	int				end;
	int				*img_data;
	void			*mlx;
	void			*win;
	void			*img;
}					t_tool;



/*
** Liste chainee contenant dans chaque maillons les lignes lues;
*/
typedef struct	s_lst
{
	char			**map;
	struct	s_lst	*next;	
}				t_lst;


/*
**	Variables utilises pour le parcing du fichier depuis lequel lire;
*/
typedef	struct		s_parce
{
	int				fd;
	int				value;
	ssize_t			i;
	char			*line;
}					t_parce;



/*
** input.c
*/
int		keyboard_input(int keycode);
int		mouse_input(int keycode);

/*
** ft_all_errors
*/
void	ft_check_args(int error);
void	ft_errors(int error);


#endif
