#include "./minilibx/mlx.h"
#include "fdf.h"

int		keyboard_input(int keycode)
{
	if (keycode == 53)
		exit(0);
	ft_putstr("Jai bien la key numero "),
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}

int		mouse_input(int keycode)
{
	ft_putstr("Jai bien la key numero "),
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}
