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
	t_lst		*lst;
	t_lst		*tmp;
	(void)argc;
	// ft_check_args(argc);
	tool.color = 0xFF00FF;
	tool.mlx = mlx_init();
	tool.win = mlx_new_window(tool.mlx, 600, 600, "600 x 600");
	tool.img = mlx_new_image(tool.mlx, 600, 600);
	tool.img_data = (int *)mlx_get_data_addr (tool.img, &tool.bpp, &tool.sl, &tool.end);

	if (!(lst = (t_lst *)malloc(sizeof(t_lst))))
		return (0);
	tmp = lst;
	if (!(box.fd = open(argv[1], O_RDONLY)))
		return (0);
	int i = 0;
		// ft_map_error(int);
	while ((box.value = get_next_line(box.fd, &box.line) != 0))
	{
		printf("value = %d\n", box.value);
		tmp->map = ft_strsplit(box.line, ' ');
		if (!(tmp->next = (t_lst *)malloc(sizeof(t_lst))))
		return (0);
		while (tmp->map[i])
		{
			printf("%d  ", ft_atoi(tmp->map[i]));
			i++;
		}
		printf("\n");
		tmp = tmp->next;
		i = 0;
		// while (tmp->map)
	}
	tmp->map = NULL;
	tmp->next = NULL;
	tmp = lst;
	// ft_pixel_image(195, 115, tool, tool.color);

	mlx_put_image_to_window(tool.mlx, tool.win, tool.img, 0, 0);
	mlx_mouse_hook(tool.win, (*mouse_input), 0);
	mlx_key_hook(tool.win, (*keyboard_input), 0);
	mlx_loop(tool.mlx);
	return (0);
}
