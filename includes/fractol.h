/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:45:34 by cde-laro          #+#    #+#             */
/*   Updated: 2017/03/20 18:24:22 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "libft.h"
# include "keys.h"
# include <limits.h>

# define DB(x) ft_putendl(x)
# define SQ(x) x * x

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_mandel
{
	t_point		a;
	t_point		image;
	t_point		cur;
	long double	zoom;
	int			iter;
	int			*color;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	t_point		start;
	t_point		mouse;
	int			mode;
}				t_mandel;

typedef struct	s_img
{
	void		*ptr_img;
	char		*bts;
	int			size_line;
	int			bpp;
	int			end;
}				t_img;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_mandel	*c;
	char		*data;
	char		*name;
	int			drawed;
	int			win_x;
	int			win_y;
	int			fract;
	int			col;
}				t_env;

void			init(t_env *e, int id);
int				key_funct(int k, t_env *e);
int				mouse_code(int x, int y, t_env *e);
int				red_cross(int key, t_env *e);
void			print_error(int code);
void			pix_put_img(t_env *e, int x, int y, int color);
void			mandelbrot(t_env *e);
void			init_mandel(t_env *e);
void			init_current(t_env *e);
void			zoom_mandel(t_env *e, int zoom);
void			iter_mandel(t_env *e, int iter);
void			init_img(t_env *e);
void			init_julia(t_env *e);
void			julia(t_env *e);
void			img_mandel(t_env *e);
void			init_ship(t_env *e);
void			ship(t_env *e);
double			win_to_fract_x(t_env *e, double x);
double			win_to_fract_y(t_env *e, double y);
double			fract_to_win_x(t_env *e, double x);
double			fract_to_win_y(t_env *e, double y);
void			draw(t_env *e);
void			zoom_to_mouse(t_env *e, int x, int y, double level);
void			display_settings(t_env *e);

#endif
