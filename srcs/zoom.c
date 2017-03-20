/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 12:24:32 by cde-laro          #+#    #+#             */
/*   Updated: 2017/03/20 19:13:31 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	init_current(t_env *e)
{
	if (e->fract == 0)
		init_mandel(e);
	else if (e->fract == 1)
		init_julia(e);
	else if (e->fract == 2)
		init_ship(e);
}

void	draw(t_env *e)
{
	if (e->fract == 0)
		mandelbrot(e);
	else if (e->fract == 1)
		julia(e);
	else if (e->fract == 2)
		ship(e);
	display_settings(e);
}

void	zoom_to_mouse(t_env *e, int x, int y, double level)
{
	e->c->a.x = win_to_fract_x(e, x);
	e->c->a.y = win_to_fract_y(e, y);
	e->c->zoom *= level;
	draw(e);
}
