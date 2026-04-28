#include "fractol.h"

int mandelbrot (double cx, double cy, int maxiter)
{
    double module2 = 0;
    
    double zr = 0;
    double zi = 0;
    double new_zr = 0;

    int iter = 0;

    while(module2 < 4 && iter <= maxiter){

        new_zr = (zr * zr) - (zi * zi) + cx;
        zi = 2 * zr * zi + cy;
        zr = new_zr;
        module2 = zr * zr +  zi * zi;
        iter++;

    }
    return (iter);
}


void draw_mandelbrot(t_data *data)
{
    int    iter;
    int    color;
    double cx;
    double cy;

    data->x = 0;
    while (data->x < data->lenght)
    {
        data->y = 0;
        while (data->y < data->height)
        {
            cx = (data->x / data->lenght) * (data->xmax - data->xmin) + data->xmin;
            cy = data->ymax - (data->y / data->height) * (data->ymax - data->ymin);
            iter = mandelbrot(cx, cy, data->maxiter);
            if (iter >= data->maxiter)
                color = create_color(0, 0, 0);
            else
                color = create_color(iter % 25 * 10, iter % 8 * 8, 255);
            my_put_pixel(data, data->x, data->y, color);
            data->y++;
        }
        data->x++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}
