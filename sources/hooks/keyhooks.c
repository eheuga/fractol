#include "../fractol.h"

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
	if (keycode == XK_Escape)
		close_window(data);
	handle_move(data, keycode);
	if (keycode == XK_r)
		handle_reset(data);
	draw(data);
	return (0);
}

