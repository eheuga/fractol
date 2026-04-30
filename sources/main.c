#include "fractol.h"

void	draw(t_data *data)
{
	if (strcmp("mandelbrot", data->name) == 0)
		draw_mandelbrot(data);
	else if (strcmp("julia", data->name) == 0)
		draw_julia(data);
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
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->lenght, data->height, "Fractol");
	data->image = mlx_new_image(data->mlx, data->lenght, data->height);
	data->buffer = mlx_get_data_addr(data->image, &data->pixel_bits,
			&data->line_bytes, &data->endian);
	data->name = name;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		return (print_usage());
	if (strcmp(av[1], "mandelbrot") == 0)
	{
		if (ac != 2)
			return (print_usage());
	}
	else if (strcmp(av[1], "julia") == 0)
	{
		if (ac != 4)
			return (print_usage());
		data.cx = ft_atof(av[2]);
		data.cy = ft_atof(av[3]);
	}
	else
		return (print_usage());
    init_data(&data, av[1]);
	draw(&data);
	mlx_hook(data.win, 02, 1L << 0, &my_keyhook, &data);
	mlx_hook(data.win, 17, 1L << 5, &close_window, &data);
	mlx_hook(data.win, 04, 1L << 2, &my_mouse_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
