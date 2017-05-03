/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:44:32 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/03 23:22:11 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void		img_mandel(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img->ptr_img, 0, 0);
	mlx_destroy_image(e->mlx, e->img->ptr_img);
	init_img(e);
}

void		init_mandel(t_env *e)
{
	e->c = (t_mandel *)malloc(sizeof(t_mandel));
	e->c->a.x = 0;
	e->c->a.y = 0;
	e->c->zoom = 5;
	e->c->iter = 40;
}

void		mandelbrot(t_env *e)
{
	int		i;
	double	tmp;

	e->c->cur.x = -1;
	while (++e->c->cur.x < e->win_x)
	{
		e->c->cur.y = -1;
		while (++e->c->cur.y < e->win_y)
		{
			e->c->c_r = win_to_fract_x(e, e->c->cur.x);
			e->c->c_i = win_to_fract_y(e, e->c->cur.y);
			e->c->z_r = 0;
			e->c->z_i = 0;
			i = 0;
			while (SQ(e->c->z_r) + SQ(e->c->z_i) < 4 && i < e->c->iter)
			{
				tmp = e->c->z_r;
				ft_putchar('|');
				e->c->z_r = SQ(e->c->z_r) - SQ(e->c->z_i) + e->c->c_r;
				e->c->z_i = 2 * tmp * e->c->z_i + e->c->c_i;
				i++;
			}
			pix_put_img(e, e->c->cur.x, e->c->cur.y, i);
		}
	}
	img_mandel(e);
}
