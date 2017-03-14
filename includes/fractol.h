/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:23:05 by fdel-car          #+#    #+#             */
/*   Updated: 2016/03/22 21:40:48 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"

# define SQ(x) x * x

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	int				size_x;
	int				size_y;
	int				iter;
	int				iter_m;
	double			cx;
	double			cy;
	double			zx;
	double			zy;
	double			zoom_x;
	double			zoom_y;
	int				x;
	int				y;
	double			tmp;
	int				bpp;
	int				sizeline;
	int				endian;
	char			*disp;
	int				zoom;
	double			move_x;
	double			move_y;
	int				frac;
	int				var_c;
	double			motion_x;
	double			motion_y;
	int				snare;
	int				l_x1;
	int				l_y1;
	int				l_x2;
	int				l_y2;
	int				err;
	int				e2;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	double			zx2;
	double			zy2;
}					t_data;

void				ft_draw_line(t_data *d, unsigned int color);
int					ft_abs(int a);
void				ft_start_mandelbrot(t_data *d);
void				ft_start_julia(t_data *d);
void				ft_start_burningship(t_data *d);
void				ft_change(t_data *d);
int					ft_key(int keycode, t_data *d);
int					ft_mouse(int keycode, int x, int y, t_data *d);
void				ft_setpixel(t_data *d, unsigned int color);
void				ft_mandelbrot(t_data *d);
void				ft_julia(t_data *d);
void				ft_burningship(t_data *d);
int					ft_color(t_data *d);
void				ft_rand_color(t_data *d);
int					ft_motion(int x, int y, t_data *d);

#endif
