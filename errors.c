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
		ft_putendl("too many arguments.\nusage: ./fdf [map]");
	if (argc < 2)
		ft_putendl("none map found.\nusage: ./fdf [map]");
	exit(EXIT_FAILURE);
}