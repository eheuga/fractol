void compute_pixel(t_data *data)
{
    double cr = (data->x / data->lenght) * (data->xmax - data->xmin) + data->xmin;
    double ci = data->ymax - (data->y / data->height) * (data->ymax - data->ymin);
    int    iter;
    int    color;

    if (data->fractal_type == MANDELBROT)
        iter = mandelbrot(cr, ci, data->maxiter);
    else
        iter = julia(cr, ci, data->cx, data->cy, data->maxiter);

    if (iter >= data->maxiter)
        color = 0;
    else
        color = pick_color(iter);

    my_put_pixel(data, data->x, data->y, color);
}