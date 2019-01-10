/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setpixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 21:36:50 by fdel-car          #+#    #+#             */
/*   Updated: 2016/03/21 18:44:03 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "time.h"
#include <unistd.h>

void	ft_rand_color(t_data *d)
{
	time_t	curtime;

	curtime = time(0) % 60 + 1;
	d->var_c = d->var_c ^ (curtime * 1000);
}

void	ft_setpixel(t_data *d, unsigned int color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				i;

	if (d->x > d->size_x || d->y > d->size_y || d->x < 0 || d->y < 0)
		return ;
	i = d->y * d->sizeline + d->x * d->bpp / 8;
	r = (color & 0xFF);
	g = ((color & 0xFF00) >> 8);
	b = ((color & 0xFF0000) >> 16);
	d->disp[i] = r;
	d->disp[i + 1] = g;
	d->disp[i + 2] = b;
}

void	pixel_put(t_data *d, unsigned int color)
{
	d->x = d->l_x1;
	d->y = d->l_y1;
	ft_setpixel(d, color);
}

int		ft_check_line(t_data *d)
{
	if ((d->sx == 1 && d->l_x1 > d->l_x2) || (d->sx == -1 &&
	d->l_x1 < d->l_x2) || (d->l_x1 == d->l_x2 && d->l_y1 == d->l_y2))
		return (0);
	return (1);
}

void	ft_draw_line(t_data *d, unsigned int color)
{
	d->dx = ft_abs(d->l_x2 - d->l_x1);
	d->dy = ft_abs(d->l_y2 - d->l_y1);
	d->sx = d->l_x1 < d->l_x2 ? 1 : -1;
	d->sy = d->l_y1 < d->l_y2 ? 1 : -1;
	d->err = (d->dx < d->dy ? d->dx : -d->dy) / 2;
	while (d->iter_m > 0)
	{
		if (!ft_check_line(d))
			break ;
		d->e2 = d->err;
		if (d->e2 > -d->dx)
		{
			d->err -= d->dy;
			d->l_x1 += d->sx;
		}
		if (d->e2 < d->dy)
		{
			d->err += d->dx;
			d->l_y1 += d->sy;
		}
		if (!ft_check_line(d))
			break ;
		pixel_put(d, color);
	}
}
