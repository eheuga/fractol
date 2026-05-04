/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <emheuga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:28:05 by emheuga           #+#    #+#             */
/*   Updated: 2026/05/04 15:05:19 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <X11/keysym.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*image;
	double	x;
	double	y;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	height;
	double	lenght;
	int		maxiter;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	double	cx;
	double	cy;
	char	*name;
	int		color_mode;
}			t_data;

int		get_color(int iter, int maxiter, int color_mode);
void	draw(t_data *data);
int		close_window(t_data *data);
int		my_keyhook(int keycode, t_data *data);
int		my_mouse_hook(int button, int x, int y, t_data *data);
int		mandelbrot(double cx, double cy, int maxiter);
int		julia(t_data *data, double zr, double zi);
void	my_put_pixel(t_data *data, double x, double y, int color);
int		print_usage(void);
double	ft_atof(char *str);
int		ft_strcmp(const char *s1, const char *s2);
#endif
