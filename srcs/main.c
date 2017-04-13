/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:57:05 by cde-laro          #+#    #+#             */
/*   Updated: 2017/03/20 19:10:59 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			detect_fract(char *str)
{
	if (ft_strequ(ft_strtolower(str), "mandelbrot"))
		return (0);
	else if (ft_strequ(ft_strtolower(str), "julia"))
		return (1);
	else if (ft_strequ(ft_strtolower(str), "burning-ship"))
		return (2);
	return (-1);
}

void		display_usage(void)
{
	ft_putendl_fd("Incorrect usage: ./fractol [fractal name]", 2);
	ft_putendl_fd("Available fractals : mandelbrot, julia and burning-ship", 2);
	exit (0);
}

int			main(int ac, char **av)
{
	t_env		e;
	int			id;

	id = 0;
	if (ac == 2)
	{
		if ((id = detect_fract(av[1])) == -1)
			display_usage();
	}
	else
		display_usage();
	e.win_x = 800;
	e.win_y = 600;
	DB("preinitialisation");
	init(&e, id);
	DB("postinitialisation");
	init_current(&e);
	draw(&e);
	mlx_loop(e.mlx);
}
