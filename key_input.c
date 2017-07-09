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

int		pressed_key(int keycode, t_mlx *tool)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
		printf("GROSSE MERDEW\n");
	ft_putstr("Jai bien la key numero ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}

int		mouse_key(int keycode)
{
	ft_putstr("Jai bien la key numero ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}
