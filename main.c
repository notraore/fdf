#include "./minilibx/mlx.h"
#include "fdf.h"

int main(void)
{
	t_tool	tool;

	tool.color = 0xFF00FF;
	tool.mlx = mlx_init();
	tool.win = mlx_new_window(tool.mlx, 600, 600, "600 x 600");
	tool.img = mlx_new_image(tool.mlx, 600, 600);
	tool.img_data = (int *)mlx_get_data_addr (tool.img, &tool.bpp, &tool.sl, &tool.end);

	int start_x = 65, start_y = 50, end_x = 300, end_y = 330;
	int x = start_x;

	while (x <= end_x)
	{
		mlx_pixel_put(tool.mlx, tool.win, x, start_y+((end_y - start_y) * (x - start_x)) / (end_x - start_x), tool.color);
		x++;
		// if (start_y < end_y)
			// y--;
		// else
			// y++;
	}

	// mlx_put_image_to_window(tool.mlx, tool.win, tool.img, 0, 0);
	mlx_mouse_hook(tool.win, (*mouse_input), 0);
	mlx_key_hook(tool.win, (*keyboard_input), 0);
	mlx_loop(tool.mlx);
	return (0);
}
