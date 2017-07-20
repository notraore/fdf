/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 18:17:51 by notraore          #+#    #+#             */
/*   Updated: 2017/07/08 18:17:54 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "toolbox.h"

int		pressed_key(int keycode)//, t_mlx *tool)
{

	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode  == 126)
	{
		printf("%d\n", __LINE__);
	}
	ft_putstr("Jai bien la key numero  ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}

int		mouse_key(int keycode)//, t_mlx *ptr)
{
	ft_putstr("Jai bien la key numero mouse");
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}
