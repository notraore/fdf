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

	// tool.img_data[(0+1*600*10)+(0+1*15)] = tool.color;
	// tool.img_data[(0+1*600*20)+(0+1*20)] = tool.color;
	// tool.img_data[(0+1*600*30)+(0+1*25)] = tool.color;
	// tool.img_data[(0+1*600*40)+(0+1*30)] = tool.color;
	// tool.img_data[(0+1*600*50)+(0+1*35)] = tool.color;
	// tool.img_data[(0+1*600*60)+(0+1*40)] = tool.color;
	// tool.img_data[(0+1*600*70)+(0+1*45)] = tool.color;
	// tool.img_data[(0+1*600*80)+(0+1*50)] = tool.color;
	// tool.img_data[(0+1*600*90)+(0+1*55)] = tool.color;
	// tool.img_data[(0+1*600*100)+(0+1*60)] = tool.color;
	// tool.img_data[(0+1*600*110)+(0+1*65)] = tool.color;

	// int y = 110;
	// while (i < 50)
	// {
	// 	tool.img_data[(65)+(600*y)] = 0xFF;
	// 	i++;
	// 	y--;
	// }
	int start_x = 65,/*, start_y = 600, */end_x = 110;//, end_y = 400;
	while (start_x != end_x)
	{
		tool.img_data[(start_x)] = tool.color;// + (start_y*y)] = 0xFF;
		start_x++;
		// while (start_y != end_y)
			// start_y++;
		// y--;
	}


	mlx_put_image_to_window(tool.mlx, tool.win, tool.img, 0, 0);
	mlx_mouse_hook(tool.win, (*mouse_input), 0);
	mlx_key_hook(tool.win, (*keyboard_input), 0);
	mlx_loop(tool.mlx);
	return (0);
}
