/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:11:11 by fdel-car          #+#    #+#             */
/*   Updated: 2016/03/21 17:24:34 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_change(t_data *d)
{
	mlx_clear_window(d->mlx, d->win);
	d->img = mlx_new_image(d->mlx, d->size_x, d->size_y);
	d->disp = mlx_get_data_addr(d->img, &(d->bpp), &(d->sizeline),
	&(d->endian));
	if (d->frac == 2)
		ft_start_julia(d);
	if (d->frac == 1)
		ft_start_mandelbrot(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	mlx_destroy_image(d->mlx, d->img);
	mlx_string_put(d->mlx, d->win, 20, 30, 0xFFFFFF, ft_itoa(d->iter_m));
}

void	ft_julia(t_data *d)
{
	d->zoom = 200;
	d->x1 = -2;
	d->x2 = 2;
	d->y1 = -1.4;
	d->y2 = 1.4;
	d->snare = 0;
	d->var_c = 0x000000;
	d->size_x = (d->x2 - d->x1) * d->zoom;
	d->size_y = (d->y2 - d->y1) * d->zoom;
	d->iter_m = 50;
	d->move_x = 0;
	d->move_y = 0;
	d->motion_x = 0.255;
	d->motion_y = 0.010;
	d->zoom_x = d->size_x / (d->x2 - d->x1);
	d->zoom_y = d->size_y / (d->y2 - d->y1);
}

void	ft_mandelbrot(t_data *d)
{
	d->zoom = 200;
	d->x1 = -2.1;
	d->x2 = 0.6;
	d->y1 = -1.2;
	d->y2 = 1.2;
	d->snare = 1;
	d->var_c = 0x000000;
	d->size_x = (d->x2 - d->x1) * d->zoom;
	d->size_y = (d->y2 - d->y1) * d->zoom;
	d->iter_m = 50;
	d->move_x = 0;
	d->move_y = 0;
	d->zoom_x = d->size_x / (d->x2 - d->x1);
	d->zoom_y = d->size_y / (d->y2 - d->y1);
}
