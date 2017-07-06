#include "./minilibx/mlx.h"
#include "fdf.h"
#include <stdio.h>

void	ft_pixel_image(int x, int y, t_tool img, int color)
{
	img.img_data[x + WIDTH * y] = color;
}

int main(int argc, char **argv)
{
	t_tool		tool;
	t_parce		box;
	int			count;
	int			***map;
	int			i;
	int			j;
	char		**norme;
	i = 0;
	j = 0;
	count = 0;
	if (argc != 2)
		ft_check_args(argc);
	tool.color = 0xFF00FF;
	tool.mlx = mlx_init();
	tool.win = mlx_new_window(tool.mlx, WIDTH, HEIGHT, "600 x 600");
	tool.img = mlx_new_image(tool.mlx, WIDTH, HEIGHT);
	tool.img_data = (int *)mlx_get_data_addr(tool.img, &tool.bpp, &tool.sl, &tool.end);

	if (!(box.fd = open(argv[1], O_RDONLY)))
		return (0);
	while ((box.value = get_next_line(box.fd, &box.line) != 0))
		count++;
	printf("%d\n", count);
	if (!(map = (int ***)malloc(sizeof(int **) * count)))
		return (0);
	// if (!(map = (int **)malloc(sizeof(int) *  count)))
		// return (0);
	// if (!(box.fd = open(argv[1], O_RDONLY)))
		// return (0);
	// printf("salut 1\n");
	while ((box.value = get_next_line(box.fd, &box.line) != 0))
	{
		norme
	}
	mlx_put_image_to_window(tool.mlx, tool.win, tool.img, 0, 0);
	mlx_mouse_hook(tool.win, (*mouse_input), 0);
	mlx_key_hook(tool.win, (*keyboard_input), 0);
	mlx_loop(tool.mlx);
	return (0);
}


