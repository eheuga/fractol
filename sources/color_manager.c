/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <emheuga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:59:13 by emheuga           #+#    #+#             */
/*   Updated: 2026/05/04 15:05:19 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	create_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

static int	get_color_red(int iter)
{
	int	color;

	color = create_color(iter % 25 * 10, iter % 8 * 4, 0);
	return (color);
}

static int	get_color_blue(int iter)
{
	int	color;

	color = create_color(0, iter % 10 * 10, iter % 25 * 10);
	return (color);
}

static int	get_color_green(int iter)
{
	int	color;

	color = create_color(iter % 5 * 8, iter % 25 * 10, iter % 3 * 6);
	return (color);
}

int	get_color(int iter, int maxiter, int color_mode)
{
	int	color;

	if (iter >= maxiter)
	{
		color = create_color(0, 0, 0);
		return (color);
	}
	if (color_mode == 1)
	{
		color = get_color_red(iter);
		return (color);
	}
	if (color_mode == 2)
	{
		color = get_color_blue(iter);
		return (color);
	}
	if (color_mode == 3)
	{
		color = get_color_green(iter);
		return (color);
	}
	return (get_color_red(iter));
}
