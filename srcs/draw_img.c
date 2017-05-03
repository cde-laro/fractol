/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:27:59 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/03 23:14:17 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	draw_line(t_env *e, t_point a, t_point b, int z)
{
	t_point		d;
	t_point		s;
	int			e1;
	int			e2;

	d.x = ABS(b.x - a.x);
	d.y = ABS(b.y - a.y);
	s.x = (a.x < b.x ? 1 : -1);
	s.y = (a.y < b.y ? 1 : -1);
	e1 = (d.x > d.y ? d.x : -d.y) / 2;
	while (a.x != b.x || a.y != b.y)
	{
		pix_put_img(e, a.y, a.x, z);
		e2 = e1;
		if (e2 > -d.x)
		{
			e1 -= d.y;
			a.x += s.x;
		}
		if (e2 < d.y)
		{
			e1 += d.x;
			a.y += s.y;
		}
	}
}

void	pix_put_img(t_env *e, int x, int y, int iter)
{
	int		r;
	int		g;
	int		b;
	int		color;

	if (iter >= e->c->iter)
		return ;

	//iter = iter * 255 / (e->c->iter % 255 + 1);
	//color = 0xFF000000;
	color = e->colors[iter % 48];
	if (e->col >= 0 && e->col <= 3)
	{
		r = ((color & 0xFF0000) >> 16);
		g = ((color & 0xFF00) >> 8);
		b = (color & 0xFF);
	}
	if (y >= 0 && x >= 0 && y < e->win_y && x < e->win_x)
	{
		e->img->bts[(y * e->img->size_line) + ((e->img->bpp / 8) * x) + 2] = r;
		e->img->bts[(y * e->img->size_line) + ((e->img->bpp / 8) * x) + 1] = g;
		e->img->bts[(y * e->img->size_line) + ((e->img->bpp / 8) * x)] = b;
	}
}
