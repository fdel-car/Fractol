/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 21:01:25 by fdel-car          #+#    #+#             */
/*   Updated: 2016/03/22 22:20:55 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	ft_start_mandelbrot(t_data *d)
{
	d->x = 0;
	while (d->x < d->size_x)
	{
		d->y = 0;
		while (d->y < d->size_y)
		{
			d->cx = d->x / d->zoom_x + d->x1 + d->move_x;
			d->cy = d->y / d->zoom_y + d->y1 + d->move_y;
			d->zx = 0;
			d->zy = 0;
			d->iter = 0;
			while (d->iter < d->iter_m && SQ(d->zx) + SQ(d->zy) < 4)
			{
				d->tmp = d->zx;
				d->zx = SQ(d->zx) - SQ(d->zy) + d->cx;
				d->zy = 2 * d->zy * d->tmp + d->cy;
				d->iter++;
			}
			ft_setpixel(d, ft_color(d));
			d->y++;
		}
		d->x++;
	}
}

void	ft_start_julia(t_data *d)
{
	d->x = 0;
	while (d->x < d->size_x)
	{
		d->y = 0;
		while (d->y < d->size_y)
		{
			d->cx = d->motion_x;
			d->cy = d->motion_y;
			d->zx = d->x / d->zoom_x + d->x1 + d->move_x;
			d->zy = d->y / d->zoom_y + d->y1 + d->move_y;
			d->iter = 0;
			while (d->iter < d->iter_m && SQ(d->zx) + SQ(d->zy) < 4)
			{
				d->tmp = d->zx;
				d->zx = SQ(d->zx) - SQ(d->zy) + d->cx;
				d->zy = 2 * d->zy * d->tmp + d->cy;
				d->iter++;
			}
			ft_setpixel(d, ft_color(d));
			d->y++;
		}
		d->x++;
	}
}

void	ft_start_burningship(t_data *d)
{
	d->y = 0;
	while (d->y < d->size_y)
	{
		d->x = 0;
		while (d->x < d->size_x)
		{
			d->iter = 0;
			d->zx = 0;
			d->zy = 0;
			d->zx2 = 0;
			d->zy2 = 0;
			d->cx = d->x / d->zoom_x + d->x1 + d->move_x;
			d->cy = d->y / d->zoom_y + d->y1 + d->move_y;
			while (d->iter++ < d->iter_m && (d->zx2 + d->zy2) < 4)
			{
				d->zy = 2 * fabs(d->zx * d->zy) + d->cy;
				d->zx = d->zx2 - d->zy2 - d->cx;
				d->zx2 = SQ(d->zx);
				d->zy2 = SQ(d->zy);
			}
			ft_setpixel(d, ft_color(d));
			d->x++;
		}
		d->y++;
	}
}
