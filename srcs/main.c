/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <fdel-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 17:49:07 by fdel-car          #+#    #+#             */
/*   Updated: 2018/09/19 15:22:40 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_check(char *str)
{
	if (strcmp(str, "burningship") == 0)
		return (3);
	if (strcmp(str, "julia") == 0)
		return (2);
	if (strcmp(str, "mandelbrot") == 0)
		return (1);
	return (0);
}

void	init_mlx(t_data *d, char *str)
{
	char	*tmp;

	d->win = mlx_new_window(d->mlx, d->size_x, d->size_y, str);
	d->img = mlx_new_image(d->mlx, d->size_x, d->size_y);
	d->disp = mlx_get_data_addr(d->img, &(d->bpp), &(d->sizeline),
	&(d->endian));
	if (d->frac == 3)
		ft_start_burningship(d);
	if (d->frac == 2)
		ft_start_julia(d);
	if (d->frac == 1)
		ft_start_mandelbrot(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	mlx_destroy_image(d->mlx, d->img);
	tmp = ft_itoa(d->iter_m);
	mlx_string_put(d->mlx, d->win, 20, 30, 0xFFFFFF, tmp);
	free(tmp);
	mlx_hook(d->win, 2, 1, ft_key, d);
	mlx_mouse_hook(d->win, ft_mouse, d);
	mlx_hook(d->win, 6, (1L << 6), ft_motion, d);
	mlx_loop(d->mlx);
}

char	*ft_str(void)
{
	char *str;

	str = "Give julia, burningship or mandelbrot as argument for the program";
	return (str);
}

int		main(int ac, char **av)
{
	t_data	*d;
	char	*str;

	d = (t_data *)malloc(sizeof(t_data));
	str = ft_str();
	if (ac != 2)
	{
		printf("%s\n", str);
		return (0);
	}
	d->frac = ft_check(av[1]);
	if (!d->frac)
	{
		printf("%s\n", str);
		return (0);
	}
	d->mlx = mlx_init();
	if (d->frac == 3)
		ft_burningship(d);
	if (d->frac == 2)
		ft_julia(d);
	if (d->frac == 1)
		ft_mandelbrot(d);
	init_mlx(d, av[1]);
	free(d);
}
