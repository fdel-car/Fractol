/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortcut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 22:10:32 by fdel-car          #+#    #+#             */
/*   Updated: 2016/03/22 22:19:43 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

void	ft_move(int keycode, t_data *d)
{
	if (keycode == 126)
		d->move_y -= 10 / d->zoom_x;
	if (keycode == 123)
		d->move_x -= 10 / d->zoom_x;
	if (keycode == 124)
		d->move_x += 10 / d->zoom_x;
	if (keycode == 125)
		d->move_y += 10 / d->zoom_x;
	if (keycode == 71)
	{
		if (d->frac == 3)
			ft_burningship(d);
		if (d->frac == 2)
			ft_julia(d);
		if (d->frac == 1)
			ft_mandelbrot(d);
	}
	if (keycode == 49)
	{
		if (d->snare == 1)
			ft_rand_color(d);
	}
}

int		ft_key(int keycode, t_data *d)
{
	if (keycode == 69)
	{
		if (d->iter_m < 400)
			d->iter_m = d->iter_m * 1.25 + 1;
	}
	if (keycode == 78)
	{
		if (d->iter_m > 2)
			d->iter_m = d->iter_m * 0.75;
	}
	if (keycode == 53)
	{
		free(d);
		exit(0);
	}
	if (keycode == 35)
	{
		if (d->snare == 1 && d->frac == 2)
			d->snare = 0;
		else
			d->snare = 1;
	}
	ft_move(keycode, d);
	ft_change(d);
	return (0);
}

int		ft_mouse(int keycode, int x, int y, t_data *d)
{
	if (keycode == 4)
	{
		d->zoom_x = d->zoom_x * 1.10 + 1;
		d->zoom_y = d->zoom_y * 1.10 + 1;
		d->move_x += (x / d->zoom_x) / 10;
		d->move_y += (y / d->zoom_y) / 10;
	}
	if (keycode == 5)
	{
		d->zoom_x = d->zoom_x * 0.90;
		d->zoom_y = d->zoom_y * 0.90;
		d->move_x -= ((d->size_x - x) / d->zoom_x) / 10;
		d->move_y -= ((d->size_y - y) / d->zoom_y) / 10;
	}
	ft_change(d);
	return (0);
}

int		ft_motion(int x, int y, t_data *d)
{
	double		tmp_x;
	double		tmp_y;

	if (d->snare == 1)
		return (0);
	if (x < 0 || x > d->size_x || y < 0 || y > d->size_y)
		return (0);
	tmp_x = x - d->size_x / 2;
	tmp_y = y - d->size_y / 2;
	d->motion_x = (tmp_x / (d->size_x)) * 2;
	d->motion_y = (tmp_y / (d->size_y)) * 2;
	ft_rand_color(d);
	ft_change(d);
	return (0);
}
