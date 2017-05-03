/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:57:58 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/04 00:10:36 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_settings(t_env *e)
{
	system("clear");
	ft_putstr("----- Current settings -----\nZoom\t: ");
	ft_putnbr(0.1 / e->c->zoom);
	ft_putstr("\nIterations: ");
	ft_putnbr(e->c->iter);
}
