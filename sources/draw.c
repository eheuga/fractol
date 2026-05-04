/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <emheuga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:56:51 by emheuga           #+#    #+#             */
/*   Updated: 2026/05/04 15:05:19 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_iter(t_data *data, double x, double y)
{
	int	iter;

	if (ft_strcmp(data->name, "mandelbrot") == 0)
		iter = mandelbrot(x, y, data->maxiter);
	else
		iter = julia(data, x, y);
	return (iter);
}

void	draw(t_data *data)
{
	double	cx;
	double	cy;
	int		color;
	int		iter;

	data->x = 0;
	while (data->x < data->lenght)
	{
		data->y = 0;
		while (data->y < data->height)
		{
			cx = (data->x / data->lenght) * (data->xmax - data->xmin)
				+ data->xmin;
			cy = data->ymax - (data->y / data->height)
				* (data->ymax - data->ymin);
			iter = get_iter(data, cx, cy);
			color = get_color(iter, data->maxiter, data->color_mode);
			my_put_pixel(data, data->x, data->y, color);
			data->y++;
		}
		data->x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}
