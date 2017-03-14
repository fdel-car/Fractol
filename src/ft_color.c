/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 19:59:38 by fdel-car          #+#    #+#             */
/*   Updated: 2016/03/22 22:29:39 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int		ft_color(t_data *d)
{
	int	color;
	int r;
	int g;
	int b;

	if (d->frac == 3)
		d->iter--;
	if (d->iter == d->iter_m)
		return (0x000000);
	else
	{
		r = 0x440000 * d->iter;
		g = 0x002200 * d->iter;
		b = 0x000066 * d->iter;
		color = (r | g | b);
		color = (color ^ d->var_c);
		return (color);
	}
}
