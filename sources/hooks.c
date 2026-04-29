#include "fractol.h"

int my_keyhook(int keycode, t_data* data)
{
	double range_x;
	double range_y;

	range_x = data->xmax - data->xmin;
	range_y = data->ymax - data->ymin;

	double zoom_level = 4.0 / range_x;
	if (keycode == XK_Escape){
        mlx_destroy_window(data->mlx, data->win);
        exit (0);
    }

    if (keycode == XK_i){
        if (data->xmax - data->xmin > 0.0000000000000000001){
            data->xmin += range_x * 0.1;
            data->xmax -= range_x * 0.1;
            data->ymin += range_y * 0.1;
            data->ymax -= range_y * 0.1;
            data->maxiter = (int)(50 * (1.0 + log10(zoom_level)));
            if (data->maxiter > 500)
                data->maxiter = 500;
        }
    }
    if (keycode == XK_o){
        data->xmin -= range_x * 0.1;
        data->xmax += range_x * 0.1;
        data->ymin -= range_y * 0.1;
        data->ymax += range_y * 0.1;
    }


    if (keycode == XK_w){
        data->ymin += range_y * 0.1;
        data->ymax += range_y * 0.1;
    }

    if (keycode == XK_a){
        data->xmin -= range_x * 0.1;
        data->xmax -= range_x * 0.1;

    }

    if (keycode == XK_s){
        data->ymin -= range_y * 0.1;
        data->ymax -= range_y * 0.1;
    }


    if (keycode == XK_d){
        data->xmin += range_x * 0.1;
        data->xmax += range_x * 0.1;
    }

	if(keycode == XK_r){
		data->xmin = -2;
		data->xmax = 2;
		data->ymin = -2;
		data->ymax = 2;
		data->maxiter = 100;
	}



    draw(data);
    return (0);
}

int my_mouse_hook(int button, int x, int y, t_data *data)
{
	double range_x;
	double range_y;

	(void)x;
	(void)y;
	range_x = data->xmax - data->xmin;
	range_y = data->ymax - data->ymin;

    if (button == 4){
        if (data->xmax - data->xmin > 0.0000000000000000001){
            data->xmin += range_x * 0.1;
            data->xmax -= range_x * 0.1;
            data->ymin += range_y * 0.1;
            data->ymax -= range_y * 0.1;

            double zoom_level = 4.0 / range_x;
            data->maxiter = (int)(50 * (1.0 + log10(zoom_level)));
            if (data->maxiter > 500)
                data->maxiter = 500;
        }
    }
    else if (button == 5){
        data->xmin -= range_x * 0.1;
        data->xmax += range_x * 0.1;
        data->ymin -= range_y * 0.1;
        data->ymax += range_y * 0.1;
    }
    draw(data);
    return (0);
}

int close_window (t_data *data){
        mlx_destroy_window(data->mlx, data->win);
        exit (0);
}
