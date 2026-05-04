/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <emheuga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:28:05 by emheuga           #+#    #+#             */
/*   Updated: 2026/05/04 15:05:19 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_move(t_data *data, int keycode)
{
	double	range_x;
	double	range_y;

	range_x = data->xmax - data->xmin;
	range_y = data->ymax - data->ymin;
	if (keycode == XK_Up)
	{
		data->ymin += range_y * 0.1;
		data->ymax += range_y * 0.1;
	}
	if (keycode == XK_Down)
	{
		data->ymin -= range_y * 0.1;
		data->ymax -= range_y * 0.1;
	}
	if (keycode == XK_Left)
	{
		data->xmin -= range_x * 0.1;
		data->xmax -= range_x * 0.1;
	}
	if (keycode == XK_Right)
	{
		data->xmin += range_x * 0.1;
		data->xmax += range_x * 0.1;
	}
}

static void	handle_reset(t_data *data)
{
	data->xmin = -2;
	data->xmax = 2;
	data->ymin = -2;
	data->ymax = 2;
	data->maxiter = 100;
}

int	my_keyhook(int keycode, t_data *data)
{
	if (keycode == XK_r)
		data->color_mode = 1;
	if (keycode == XK_b)
		data->color_mode = 2;
	if (keycode == XK_g)
		data->color_mode = 3;
	if (keycode == XK_Escape)
		close_window(data);
	if (keycode == XK_n)
		handle_reset(data);
	handle_move(data, keycode);
	draw(data);
	return (0);
}
