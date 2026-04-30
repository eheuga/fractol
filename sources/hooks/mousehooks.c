#include "../fractol.h"

static void	zoom_at_point(t_data *data, double mx, double my, double zoom)
{
	data->xmin = mx + (data->xmin - mx) * zoom;
	data->xmax = mx + (data->xmax - mx) * zoom;
	data->ymin = my + (data->ymin - my) * zoom;
	data->ymax = my + (data->ymax - my) * zoom;
}

int	my_mouse_hook(int button, int x, int y, t_data *data)
{
	double	mx;
	double	my;

	mx = (x / data->lenght) * (data->xmax - data->xmin) + data->xmin;
	my = data->ymax - (y / data->height) * (data->ymax - data->ymin);
	if (button == 4 && data->xmax - data->xmin > 0.00000000001)
		zoom_at_point(data, mx, my, 0.9);
	else if (button == 5)
		zoom_at_point(data, mx, my, 1.0 / 0.9);
	else
		return (0);
	draw(data);
	return (0);
}