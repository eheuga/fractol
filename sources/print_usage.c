/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <emheuga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:16:00 by emheuga           #+#    #+#             */
/*   Updated: 2026/05/04 14:03:20 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	print_usage(void)
{
	write(1, "Usage:\n", 7);
	write(1, "  ./fractol mandelbrot\n", 23);
	write(1, "  ./fractol julia <cx> <cy>\n", 28);
	write(1, "    cx and cy are floats, e.g. -0.7 0.27015\n", 44);
	return (1);
}
