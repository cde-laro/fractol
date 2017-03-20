/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:44:14 by cde-laro          #+#    #+#             */
/*   Updated: 2017/03/20 19:13:10 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void		init_julia(t_env *e)
{
	e->c = (t_mandel *)malloc(sizeof(t_mandel));
	e->c->a.x = 0;
	e->c->a.y = 0;
	e->c->zoom = 4;
	iter_mandel(e, 40);
	e->c->mouse.x = 0;
	e->c->mouse.y = 0;
}

void		julia(t_env *e)
{
	int			i;
	double		tmp;

	e->c->cur.x = -1;
	while (++e->c->cur.x < e->win_x)
	{
		e->c->cur.y = -1;
		while (++e->c->cur.y < e->win_y)
		{
			e->c->c_r = e->c->mouse.x;
			e->c->c_i = e->c->mouse.y;
			e->c->z_r = win_to_fract_x(e, e->c->cur.x);
			e->c->z_i = win_to_fract_y(e, e->c->cur.y);
			i = 0;
			while (SQ(e->c->z_r) + SQ(e->c->z_i) < 4 && i < e->c->iter)
			{
				tmp = e->c->z_r;
				e->c->z_r = SQ(e->c->z_r) - SQ(e->c->z_i) + e->c->c_r;
				e->c->z_i = 2 * e->c->z_i * tmp + e->c->c_i;
				i++;
			}
			pix_put_img(e, e->c->cur.x, e->c->cur.y, i);
		}
	}
	img_mandel(e);
}
