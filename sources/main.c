#include <mlx.h>
#include <stdlib.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


typedef struct s_data{
    void *mlx;
    void *win;
	void *image;
    double x;
    double y;
    double xmin;
    double xmax;
    double ymin;
    double ymax;
    double height;
    double lenght;
    double maxiter;
	int pixel_bits;
	int line_bytes;
	int endian;
	char *buffer;
	double cx;
	double cy;
	double angle;
	char *name;

}   t_data;


int create_color (int r, int g, int b){
    return (r << 16 | g << 8 | b);
}

void my_put_pixel(t_data *data, double x, double y, int color){

	int pixel;

	pixel = (y * data->line_bytes)  + ( x * 4);

	if (x >= 0 && x < data->lenght &&  y >= 0 && y < data->height){
		if (data->endian == 1)
    	{
        	data->buffer[pixel + 0] = (color >> 24);
        	data->buffer[pixel + 1] = (color >> 16) & 0xFF;
        	data->buffer[pixel + 2] = (color >> 8) & 0xFF;
        	data->buffer[pixel + 3] = (color) & 0xFF;
    	}
    	else if (data->endian == 0)
    	{
        	data->buffer[pixel + 0] = (color) & 0xFF;
        	data->buffer[pixel + 1] = (color >> 8) & 0xFF;
        	data->buffer[pixel + 2] = (color >> 16) & 0xFF;
        	data->buffer[pixel + 3] = (color >> 24);
    	}

	}

}



void julia (t_data *data){

	double a;
	double b;
	int color;
	int iter = 0;
	double new_a;

	a = (data->x / data->lenght) * (data->xmax - data->xmin) + data->xmin;
	b = -((data->y / data->height) * (data->ymax - data->ymin)) + data->ymax;
	double aa = a*a;
	double bb = b*b;



	while ((aa + bb ) < 4 && iter < data->maxiter){

        new_a = aa - bb + data->cx;
        b = 2*a*b + data->cy;
        a =new_a;
		aa = a * a;
		bb = b *b;
        iter++;
    }

    if (iter >= data->maxiter){
        color = create_color(0,0,0);
        //mlx_pixel_put(data->mlx, data->win, data->x, data->y, color);
    }

    else {
        // AUTRE COULEURS
        color = create_color(iter % 16 * 16, iter % 8 * 8, 0);
        //color = create_color(iter % 17 * 15, iter % 13 * 19, iter % 7 * 36);
        //color = create_color(iter % 25 * 10, iter % 8 * 8, 255);
        //color = create_color(255 - (iter * 150/ data->maxiter), 0 ,300 -( iter * 150/ data->maxiter));
        //color = create_color(iter, iter, iter);
        //mlx_pixel_put(data->mlx, data->win, data->x, data->y, color);
    }
		my_put_pixel(data, data->x, data->y, color);
}


void do_maths (t_data *data){
    double cx;
    double cy;
    int iter = 0;
    double new_a = 0;
    int color;
    cx = (data->x / data->lenght) * (data->xmax - data->xmin) + data->xmin;
    cy = -((data->y / data->height) * (data->ymax - data->ymin)) + data->ymax;

    double a = 0;
    double b = 0;

	double aa = 0;
	double bb = 0;

    while ((aa + bb ) < 4 && iter < data->maxiter){

        new_a = aa - bb + cx;
        b = 2*a*b + cy;
        a =new_a;
		aa = a * a;
		bb = b *b;
        iter++;
    }

    if (iter >= data->maxiter){
        color = create_color(0,0,0);
        //mlx_pixel_put(data->mlx, data->win, data->x, data->y, color);
    }

    else {
        // AUTRE COULEURS
        //color = create_color(iter % 16 * 16, iter % 8 * 8, 0);
        //color = create_color(iter % 17 * 15, iter % 13 * 19, iter % 7 * 36);
        color = create_color(iter % 25 * 10, iter % 8 * 8, 255);
        //color = create_color(255 - (iter * 150/ data->maxiter), 0 ,300 -( iter * 150/ data->maxiter));
        //color = create_color(iter, iter, iter);
        //mlx_pixel_put(data->mlx, data->win, data->x, data->y, color);
    }
		my_put_pixel(data, data->x, data->y, color);

}

void draw (t_data *data){
    data->x = 0;
    data->y = 0;
    while (data->x < data->lenght)
    {
    data->y = 0;
        while (data->y < data->height){


			if (strcmp("mandelbrot", data->name) == 0)
				do_maths(data);

			else if (strcmp("julia", data->name) == 0)
				julia(data);
            else
				return ;
			data->y++;
        }
    data->x++;
    }
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}
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

	if (keycode == XK_j){

		data->angle += 0.005;
		data->cx = 0.7 * cos(data->angle);
		data->cy = 0.7 * sin(data->angle);
		printf("%f\n", data->angle);
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

int main (int ac, char **av){

    t_data data;

	if (ac != 2)
		return (0);

    data.x = 0;
    data.y = 0;
    data.xmin = -2;
    data.xmax = 2;
    data.ymin = -2;
    data.ymax = 2;
    data.height = 800;
    data.lenght = 800;
    data.maxiter = 100;
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, data.lenght, data.height, "Fractol");
	data.image = mlx_new_image(data.mlx, data.lenght, data.height);
	data.buffer = mlx_get_data_addr(data.image, &data.pixel_bits, &data.line_bytes, &data.endian);
	data.angle = 1.3;
	data.cx = 0.7 * cos(data.angle);
	data.cy = 0.7 * sin(data.angle);
	data.name = av[1];


	draw(&data);

    mlx_hook(data.win, 02, 1L <<0, &my_keyhook, &data);
	mlx_hook(data.win, 17, 1L <<5, &close_window, &data);

    mlx_hook(data.win, 04, 1L <<2, &my_mouse_hook, &data);

    mlx_loop(data.mlx);
    return (0);

}
