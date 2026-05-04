/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <emheuga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:28:05 by emheuga           #+#    #+#             */
/*   Updated: 2026/05/04 15:05:19 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_data *data, double zr, double zi)
{
	double	module2;
	double	new_zr;
	int		iter;

	module2 = 0;
	new_zr = 0;
	iter = 0;
	while (module2 < 4 && iter < data->maxiter)
	{
		new_zr = (zr * zr) - (zi * zi) + data->cx;
		zi = 2 * zr * zi + data->cy;
		zr = new_zr;
		module2 = zr * zr + zi * zi;
		iter++;
	}
	return (iter);
}
