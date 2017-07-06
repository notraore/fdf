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
	int			i;
	int			j;
	char		***cpy;
	int			tile = 5;

	i = 0;
	j = 0;
	count = 0;
	if (argc != 2)
		ft_check_args(argc);
	tool.color = 0xFF00FF;
	tool.mlx = mlx_init();
	tool.win = mlx_new_window(tool.mlx, WIDTH, HEIGHT, "600 x 600");
	tool.img = mlx_new_image(tool.mlx, WIDTH, HEIGHT);
	tool.img_data = (int *)mlx_get_data_addr (tool.img, &tool.bpp, &tool.sl, &tool.end);
	printf("the one\n");

	if (!(box.fd = open(argv[1], O_RDONLY)))
		return (0);
	while((box.value = get_next_line(box.fd, &box.line)) != 0)
		count++;
	printf("%d\n", count);
	close(box.fd);
	if (!(box.fd = open(argv[1], O_RDONLY)))
		return (0);
	// count = ft_count_close_open(box.fd, &argv[1]);
	cpy = malloc(sizeof(char ***) * count);
	while ((box.value = get_next_line(box.fd, &box.line) != 0))
	{ 
		printf("%s\n","ici" );
		cpy[i] = ft_strsplit(box.line, ' ');
		i++;
	}
	cpy = realloc(cpy, sizeof(char ***));
	cpy[i] = NULL;
	printf("%s\n","la" );
	// int k;
	j = 0;
	i = 0;
	tool.x = 755;
	tool.y = 255;
	while(cpy[j])
	{
		while(cpy[j][i])
		{
			// if (ft_atoi(cpy[j][i]) == 0)
				ft_pixel_image(tool.x, tool.y, tool, tool.color);
	// 		if (ft_atoi(cpy[j][i]) == 10)
	// 			ft_pixel_image(tool.x, tool.y - 76, tool, tool.color);
	// 		tool.x += 15;
	// 		i++;
	// 	}
	// 	tile += 15;
	// 	tool.y += 10;
	// 	tool.x = 755 + tile;
	// 	i = 0;
	// 	j++;
	// }
	// printf("%s\n","la" );
	// printf("\n\n\n\n\n%s\n", cpy[6][2]);
	mlx_put_image_to_window(tool.mlx, tool.win, tool.img, 0, 0);
	mlx_mouse_hook(tool.win, (*mouse_input), 0);
	mlx_key_hook(tool.win, (*keyboard_input), 0);
	mlx_loop(tool.mlx);
	return (0);
}
