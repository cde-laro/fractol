/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:45:04 by cde-laro          #+#    #+#             */
/*   Updated: 2017/03/20 19:12:53 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

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
	exit(0);
	return (0);
}

void	init_img(t_env *e)
{
	e->img->ptr_img = mlx_new_image(e->mlx, e->win_x, e->win_y);
	e->img->bts = mlx_get_data_addr(e->img->ptr_img, &(e->img->bpp),
			&(e->img->size_line), &(e->img->end));
}

int		mouse_click(int button, int x, int y, t_env *e)
{
	if (button == 2)
	{
		zoom_to_mouse(e, x, y, 1.3);
		if (e->c->zoom > 10)
		{
			e->c->zoom = 10;
			return (0);
		}
		iter_mandel(e, e->c->iter / 1.1);
		if (e->c->iter < 1)
			iter_mandel(e, 1);
	}
	else if (button == 1)
	{
		zoom_to_mouse(e, x, y, 0.7);
		iter_mandel(e, e->c->iter * 1.2);
	}
	draw(e);
	return (0);
}

void	init(t_env *e, int id)
{
	if (!(e->mlx = mlx_init()))
		print_error(1);
	if (!(e->win = mlx_new_window(e->mlx, e->win_x, e->win_y, "Fractol")))
		print_error(2);
	if (!(e->img = (t_img *)malloc(sizeof(t_img))))
		print_error(3);
	e->fract = id;
	init_img(e);
	e->col = 0;
	mlx_hook(e->win, 17, (1L << 17), red_cross, e);
	mlx_hook(e->win, 2, 3, key_funct, e);
	mlx_hook(e->win, 6, 1L << 6, mouse_code, e);
	mlx_mouse_hook(e->win, mouse_click, e);
}
