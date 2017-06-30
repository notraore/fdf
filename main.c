#include "./minilibx/mlx.h"
#include "fdf.h"

int main(void)
{
	int x = 300, y = 300;
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 600, 600, "600 x 600");

	mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);

	mlx_loop(mlx);
	mlx_mouse_hook(win, mouse_input, 0);
	return 0;
}
