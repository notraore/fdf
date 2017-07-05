#include "./minilibx/mlx.h"
#include "fdf.h"
#include <stdio.h>

void	ft_pixel_image(int x, int y, t_tool img, int color)
{
	img.img_data[x + WIDTH * y] = color;
}

// char *ft_cpy_without_elem(char *dst, char *src, char elem, int choix)
// {
// 	int i;
// 	int len;

// 	i = 0;
// 	len = 0;
// 	while (src[i])
// 	{
// 		if (src[i] != elem)
// 		{
// 			if (choix == 1)
// 				dst[len] = src[i];
// 			len++;
// 		}
// 		i++;
// 	}
// 	if (choix == 0)
// 		ft_cpy_without_elem(ft_memalloc(sizeof(char) * len), src, elem, 1);
// 	return (dst);
// }


int main(int argc, char **argv)
{
	t_tool		tool;
	t_parce		box;
	int			count;
	// int			**map = NULL;
	int			i;
	int			j;
	char		***cpy;

	i = 0;
	j = 0;
	count = 0;
	if (argc != 2)
		ft_check_args(argc);
	tool.color = 0xFF00FF;
	tool.mlx = mlx_init();
	tool.win = mlx_new_window(tool.mlx, 600, 600, "600 x 600");
	tool.img = mlx_new_image(tool.mlx, 600, 600);
	tool.img_data = (int *)mlx_get_data_addr (tool.img, &tool.bpp, &tool.sl, &tool.end);

	if (!(box.fd = open(argv[1], O_RDONLY)))
		return (0);
	// int i = 0;
	while ((box.value = get_next_line(box.fd, &box.line) != 0))
		count++;
	close(box.fd);
	if (!(box.fd = open(argv[1], O_RDONLY)))
		return (0);
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
	int k;
	k = 0;
	i = 0;
	while(cpy[k])
	{
		while(cpy[k][i])
		{
			printf("| %s |", cpy[k][i]);
			i++;
		}
		printf("\n");
		i = 0;
		k++;
	}
	
	// close(box.fd);
	printf("salut 0\n");
	// if (!(map = (int **)malloc(sizeof(int) *  count)))
	// 	return (0);
	// if (!(box.fd = open(argv[1], O_RDONLY)))
		// return (0);
	// printf("salut 1\n");
	// while ((box.value = get_next_line(box.fd, &box.line) != 0))
	// {
	// 	while(box.line[i])
	// 	{
	// 		ft_putstr(box.line);
	// 		printf("salut 2\n");
	// 		cpy = ft_strsplit(box.line, ' ');
	// 		map[j][i] = ft_atoi(cpy);
	// 		printf("salut 3\n");
	// 		printf("%d\n", map[j][i]);
	// 		i++;
	// 	}
	// 	j++;
	// 	i = 0;
	// }
	mlx_put_image_to_window(tool.mlx, tool.win, tool.img, 0, 0);
	printf("salut 1\n");
	mlx_mouse_hook(tool.win, (*mouse_input), 0);
	printf("salut 2\n");
	mlx_key_hook(tool.win, (*keyboard_input), 0);
	printf("salut 3\n");
	mlx_loop(tool.mlx);
	printf("salut 4\n");
	return (0);
}
