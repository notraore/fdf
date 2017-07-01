#include "./minilibx/mlx.h"
#include "fdf.h"

int main(void)
{
	t_tool	tool;

	tool.mlx = mlx_init();
	tool.win = mlx_new_window(tool.mlx, 600, 600, "600 x 600");
	tool.img = (int *)mlx_new_image(tool.mlx, 600, 600);

	tool.img_data[(0+4*64) + (0+4*55)] = 0xFF;

	mlx_put_image_to_window(tool.mlx, tool.win, tool.img, 0, 0);
	mlx_mouse_hook(tool.win, (*mouse_input), 0);
	mlx_key_hook(tool.win, (*keyboard_input), 0);
	mlx_loop(tool.mlx);
	return (0);
}
