/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:57:05 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/04 00:39:42 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_error(int code)
{
	ft_putstr("An error has occured: ");
	ft_putnbr(code);
	ft_putstr(" Leaving program ...");
	exit(-1);
}

int		red_cross(int key, t_env *e)
{
	(void)key;
	(void)*e;
	system("killall afplay");
	exit(0);
	return (0);
}

int		detect_fract(char *str)
{
	if (ft_strequ(ft_strtolower(str), "mandelbrot"))
		return (0);
	else if (ft_strequ(ft_strtolower(str), "julia"))
		return (1);
	else if (ft_strequ(ft_strtolower(str), "burning-ship"))
		return (2);
	return (-1);
}

void	display_usage(void)
{
	ft_putendl_fd("Incorrect usage: ./fractol [fractal name]", 2);
	ft_putendl_fd("Available fractals : mandelbrot, julia and burning-ship", 2);
	exit(0);
}

int		main(int ac, char **av)
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
	system("afplay resources/shooting.mp3 &");
	mlx_loop(e.mlx);
}
