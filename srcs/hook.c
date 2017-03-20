/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:44:27 by cde-laro          #+#    #+#             */
/*   Updated: 2017/03/20 19:09:35 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		mouse_code(int x, int y, t_env *e)
{
	if (e->c->mode == KEY_X)
	{
		e->c->mouse.x = win_to_fract_x(e, x);
		e->c->mouse.y = win_to_fract_y(e, y);
		draw(e);
	}
	return (0);
}

void	zoom(t_env *e, int k)
{
	if (k == KEY_PAD_ADD)
		e->c->zoom *= 0.95;
	else
		e->c->zoom *= 1.05;
	printf("zoom_lvl = %Lf", e->c->zoom);
	draw(e);
}

void	move(t_env *e, int k)
{
	if (k == KEY_UP)
		e->c->a.y += 0.1;
	else if (k == KEY_DOWN)
		e->c->a.y -= 0.1;
	else if (k == KEY_LEFT)
		e->c->a.x += 0.1;
	else if (k == KEY_RIGHT)
		e->c->a.x -= 0.1;
	draw(e);
}

void	iter(t_env *e, int k)
{
	if (k == KEY_PAD_6)
		iter_mandel(e, e->c->iter * 1.05);
	else
	{
		iter_mandel(e, e->c->iter * 0.95);
		if (e->c->iter < 20)
			e->c->iter = 20;
	}
	draw(e);
}

int		key_funct(int k, t_env *e)
{
	if (k == KEY_PAD_ADD || k == KEY_PAD_SUB)
		zoom(e, k);
	if (k == KEY_PAD_9 || k == KEY_PAD_6)
		iter(e, k);
	if (k == KEY_UP || k == KEY_DOWN || k == KEY_LEFT || k == KEY_RIGHT)
		move(e, k);
	if (k == KEY_Z || k == KEY_X)
		e->c->mode = k;
	if (k == KEY_ESCAPE)
		exit(0);
	(void)e;
	return (0);
}
