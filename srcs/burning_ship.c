/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:44:14 by cde-laro          #+#    #+#             */
/*   Updated: 2017/03/23 16:31:45 by cde-laro         ###   ########.fr       */
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
	t_point		tmp;
	t_point		c;
	t_point		p;

	e->c->cur.x = -1;
	while (++e->c->cur.x < e->win_x)
	{
		e->c->cur.y = -1;
		while (++e->c->cur.y < e->win_y)
		{
			tmp.x = 0;
			tmp.y = 0;
			c.x = win_to_fract_x(e, e->c->cur.x);
			c.y = win_to_fract_y(e, e->c->cur.y);
			i = 0;
			while (i < e->c->iter)
			{
				p.x = SQ(tmp.x) - SQ(tmp.y) - c.x;
				p.y = (2 * ABS(tmp.x * tmp.y) - c.y);
				tmp.x = p.x;
				tmp.y = p.y;
				i++;
				if (SQ(p.x) + SQ(p.y) > 10)
					break ;
			}
			pix_put_img(e, e->c->cur.x, e->c->cur.y, i);
		}
	}
	img_mandel(e);
}
