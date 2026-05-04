/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <emheuga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:28:05 by emheuga           #+#    #+#             */
/*   Updated: 2026/05/04 15:05:19 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_args(t_data *data, int ac, char **av)
{
	if (ac < 2)
		return (print_usage());
	if (ft_strcmp(av[1], "mandelbrot") == 0)
	{
		if (ac != 2)
			return (print_usage());
	}
	else if (ft_strcmp(av[1], "julia") == 0)
	{
		if (ac != 4)
			return (print_usage());
		data->cx = ft_atof(av[2]);
		data->cy = ft_atof(av[3]);
	}
	else
		return (print_usage());
	return (0);
}

static void	init_data(t_data *data, char *name)
{
	data->x = 0;
	data->y = 0;
	data->xmin = -2;
	data->xmax = 2;
	data->ymin = -2;
	data->ymax = 2;
	data->height = 800;
	data->lenght = 800;
	data->maxiter = 100;
	data->mlx = NULL;
	data->win = NULL;
	data->image = NULL;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->lenght,
			data->height, "Fractol");
	data->image = mlx_new_image(data->mlx, data->lenght, data->height);
	data->buffer = mlx_get_data_addr(data->image, &data->pixel_bits,
			&data->line_bytes, &data->endian);
	data->name = name;
	data->color_mode = 1;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (check_args(&data, ac, av))
		return (1);
	init_data(&data, av[1]);
	draw(&data);
	mlx_hook(data.win, 02, 1L << 0, &my_keyhook, &data);
	mlx_hook(data.win, 17, 1L << 5, &close_window, &data);
	mlx_hook(data.win, 04, 1L << 2, &my_mouse_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
