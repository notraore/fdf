/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 12:24:07 by notraore          #+#    #+#             */
/*   Updated: 2017/06/14 15:48:17 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "toolbox.h"

void	ft_print_err(int argc)
{
	if (argc > 2)
		ft_putendl("too many arguments.\nusage: ./fdf [map] or ./fdf \"help\"");
	if (argc < 2)
		ft_putendl("none map found.\nusage: ./fdf [map] or ./fdf \"help\"");
	exit(EXIT_FAILURE);
}

void	ft_help(void)
{
	ft_putstr("\t./fdf [map] -> ");
	ft_putendl("Map exemple can be found on Map directory\n\
	\t\t\t**INPUT**\n\
	-Press 'q' and 'e' to add and substract relief.\n\
	-Press '+' and '-' to zoom in and out.\n\
	-Press directional arrows to move the image.\n\
	-Press 'esc' to exit the program.");
	exit(EXIT_SUCCESS);
}
