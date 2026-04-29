#include "../fractol.h"

int	my_mouse_hook(int button, int x, int y, t_data *data)
{
	double	range_x;
	double	range_y;
	double	zoom_level;

	(void)x;
	(void)y;
	range_x = data->xmax - data->xmin;
	range_y = data->ymax - data->ymin;
	if (button == 4)
	{
		if (data->xmax - data->xmin > 0.00000000001)
		{
			data->xmin += range_x * 0.1;
			data->xmax -= range_x * 0.1;
			data->ymin += range_y * 0.1;
			data->ymax -= range_y * 0.1;
			zoom_level = 4.0 / range_x;
			data->maxiter = (int)(50 * (1.0 + log10(zoom_level)));
			if (data->maxiter > 500)
				data->maxiter = 500;
		}
	}
	else if (button == 5)
	{
		data->xmin -= range_x * 0.1;
		data->xmax += range_x * 0.1;
		data->ymin -= range_y * 0.1;
		data->ymax += range_y * 0.1;
	}
	draw(data);
	return (0);
}