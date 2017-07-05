#include "./minilibx/mlx.h"
#include "fdf.h"

void	ft_check_args(int argc)
{
	if (argc < 2)
		ft_putendl("not enough arguments.");
	if (argc > 2)
		ft_putendl("too many arguments.");
	exit(EXIT_FAILURE);
}

void	ft_errors(int error)
{
	if (error == 1)
		exit(EXIT_FAILURE);
}