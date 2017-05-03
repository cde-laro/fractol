/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:44:14 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/03 23:50:09 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void		init_ship(t_env *e)
{
	e->c = (t_mandel *)malloc(sizeof(t_mandel));
	e->c->a.x = 1.755;
	e->c->a.y = 0.03;
	e->c->zoom = 0.1;
	e->c->iter = 40;
	e->c->mouse.x = 100;
	e->c->mouse.y = 100;
}

void		ship(t_env *e)
{
	int			i;
	double		tmp;

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
			while (i < e->c->iter && SQ(e->c->z_r) + SQ(e->c->z_i) < 10)
			{
				tmp = e->c->z_r;
				e->c->z_r = SQ(tmp) - SQ(e->c->z_i) - e->c->c_r;
				e->c->z_i = (2 * ABS(tmp * e->c->z_i) - e->c->c_i);
				i++;
			}
			pix_put_img(e, e->c->cur.x, e->c->cur.y, i);
		}
	}
	img_mandel(e);
}
