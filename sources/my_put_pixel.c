/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <emheuga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:28:05 by emheuga           #+#    #+#             */
/*   Updated: 2026/05/04 15:05:19 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_put_pixel(t_data *data, double x, double y, int color)
{
	int	offset;

	offset = (y * data->line_bytes) + (x * (data->pixel_bits / 8));
	if (x >= 0 && x < data->lenght && y >= 0 && y < data->height)
	{
		if (data->endian == 1)
		{
			data->buffer[offset + 0] = (color >> 24);
			data->buffer[offset + 1] = (color >> 16) & 0xFF;
			data->buffer[offset + 2] = (color >> 8) & 0xFF;
			data->buffer[offset + 3] = (color) & 0xFF;
		}
		else if (data->endian == 0)
		{
			data->buffer[offset + 0] = (color) & 0xFF;
			data->buffer[offset + 1] = (color >> 8) & 0xFF;
			data->buffer[offset + 2] = (color >> 16) & 0xFF;
			data->buffer[offset + 3] = (color >> 24);
		}
	}
}
