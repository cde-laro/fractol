/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:31:11 by cde-laro          #+#    #+#             */
/*   Updated: 2017/03/20 14:31:47 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		win_to_fract_x(t_env *e, double x)
{
	return (e->c->a.x + e->c->zoom * ((x - e->win_x / 2) / e->win_x));
}

double		win_to_fract_y(t_env *e, double y)
{
	return (e->c->a.y + e->c->zoom * (-(y - e->win_y / 2) / e->win_y));
}

double		fract_to_win_x(t_env *e, double x)
{
	return ((-2 * e->c->a.x * e->win_x + e->c->zoom * e->win_x + 2 * e->win_x
				* x) / (2 * e->c->zoom));
}

double		fract_to_win_y(t_env *e, double y)
{
	return (-(-2 * e->c->a.y * e->win_y - e->c->zoom * e->win_y + 2 * e->win_y
				* y) / (2 * e->c->zoom));
}
