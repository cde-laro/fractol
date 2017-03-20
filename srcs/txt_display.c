/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:57:58 by cde-laro          #+#    #+#             */
/*   Updated: 2017/03/20 18:13:25 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_settings(t_env *e)
{
	system("clear");
	ft_putstr("----- Current settings -----\nCenter\t: [");
	ft_putnbr(fract_to_win_x(e, 0));
	ft_putstr("][");
	ft_putnbr(fract_to_win_y(e, 0));
	ft_putstr("]\nZoom\t: ");
	ft_putnbr(1 / e->c->zoom * 100);
	ft_putstr("\nIterations: ");
	ft_putnbr(e->c->iter);
}
