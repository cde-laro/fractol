/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:45:04 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/04 00:40:02 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	init_color_2(t_env *e)
{
	e->colors[23] = 0x0000FFDF;
	e->colors[24] = 0x0000FFFF;
	e->colors[25] = 0x0000E07F;
	e->colors[26] = 0x0000C0FF;
	e->colors[27] = 0x0000A0FF;
	e->colors[28] = 0x000080FF;
	e->colors[29] = 0x000060FF;
	e->colors[30] = 0x000040FF;
	e->colors[31] = 0x000020FF;
	e->colors[32] = 0x000000FF;
	e->colors[33] = 0x001F80FF;
	e->colors[34] = 0x003F00FF;
	e->colors[35] = 0x006000FF;
	e->colors[36] = 0x008100FF;
	e->colors[37] = 0x00A000FF;
	e->colors[38] = 0x00BF00FF;
	e->colors[39] = 0x00DE00FF;
	e->colors[40] = 0x00FD00FF;
	e->colors[41] = 0x00FE00DF;
	e->colors[42] = 0x00FF00C0;
	e->colors[43] = 0x00FF009F;
	e->colors[44] = 0x00FF007E;
	e->colors[45] = 0x00FF005F;
	e->colors[46] = 0x00FF0040;
	e->colors[47] = 0x00FF0020;
}

void	init_color(t_env *e)
{
	e->colors = (int *)malloc(sizeof(int) * 48);
	e->colors[0] = 0x00FF0000;
	e->colors[1] = 0x00FF1F80;
	e->colors[2] = 0x00FF3F00;
	e->colors[3] = 0x00FF5F00;
	e->colors[4] = 0x00FF7F00;
	e->colors[5] = 0x00FF9F00;
	e->colors[6] = 0x00FFBF00;
	e->colors[7] = 0x00FFDF00;
	e->colors[8] = 0x00FFFF00;
	e->colors[9] = 0x00E07F00;
	e->colors[10] = 0x00C0FF00;
	e->colors[11] = 0x00A0FF00;
	e->colors[12] = 0x0080FF00;
	e->colors[13] = 0x0060FF00;
	e->colors[14] = 0x0040FF00;
	e->colors[15] = 0x0021FF00;
	e->colors[16] = 0x0002FF00;
	e->colors[17] = 0x0001FF1F;
	e->colors[18] = 0x0000FF3F;
	e->colors[19] = 0x0000FF5E;
	e->colors[20] = 0x0000FF7D;
	e->colors[21] = 0x0000FF9E;
	e->colors[22] = 0x0000FFBF;
	init_color_2(e);
}

void	init_img(t_env *e)
{
	e->img->ptr_img = mlx_new_image(e->mlx, e->win_x, e->win_y);
	e->img->bts = mlx_get_data_addr(e->img->ptr_img, &(e->img->bpp),
			&(e->img->size_line), &(e->img->end));
}

int		mouse_click(int button, int x, int y, t_env *e)
{
	if (button == 2)
	{
		zoom_to_mouse(e, x, y, 1.3);
		if (e->c->zoom > 10)
		{
			e->c->zoom = 10;
			return (0);
		}
		e->c->iter /= 1.1;
		if (e->c->iter < 1)
			e->c->iter = 1;
	}
	else if (button == 1)
	{
		zoom_to_mouse(e, x, y, 0.7);
		e->c->iter *= 1.2;
	}
	draw(e);
	return (0);
}

void	init(t_env *e, int id)
{
	if (!(e->mlx = mlx_init()))
		print_error(1);
	if (!(e->win = mlx_new_window(e->mlx, e->win_x, e->win_y, "Fractol")))
		print_error(2);
	if (!(e->img = (t_img *)malloc(sizeof(t_img))))
		print_error(3);
	e->fract = id;
	init_img(e);
	init_color(e);
	e->col = 0;
	mlx_hook(e->win, 17, (1L << 17), red_cross, e);
	mlx_hook(e->win, 2, 3, key_funct, e);
	mlx_hook(e->win, 6, 1L << 6, mouse_code, e);
	mlx_mouse_hook(e->win, mouse_click, e);
}
