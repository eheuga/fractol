#include <mlx.h>
#include <stdlib.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <math.h>


typedef struct s_data{
    void *mlx;
    void *win;
    double x;
    double y;
    double xmin;
    double xmax;
    double ymin;
    double ymax;
    double height;
    double lenght;
    double maxiter;

}   t_data;


int create_color (int r, int g, int b){
    return (r << 16 | g << 8 | b);
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

    while ((a*a + b*b ) < 4 && iter < data->maxiter){

        new_a = a*a - b*b + cx;
        b = 2*a*b + cy;
        a =new_a;
        iter++;
    }

    if (iter >= data->maxiter){
        color = create_color(0,0,0);
        mlx_pixel_put(data->mlx, data->win, data->x, data->y, color);
    }

    else {
        // AUTRE COULEURS 
        //color = create_color(iter % 16 * 16, iter % 8 * 8, 0);
        //color = create_color(iter % 17 * 15, iter % 13 * 19, iter % 7 * 36);
        //color = create_color(iter % 25 * 10, iter % 8 * 8, 255);
        //color = create_color(255 - (iter * 150/ data->maxiter), 0 ,300 -( iter * 150/ data->maxiter));
        color = create_color(iter, iter, iter);
        mlx_pixel_put(data->mlx, data->win, data->x, data->y, color);
    }
    
}

void draw (t_data *data){
    data->x = 0;
    data->y = 0;
    while (data->x < data->lenght)
    {
    data->y = 0;
        while (data->y < data->height){

            do_maths(data);
            data->y++;
        }
    data->x++;
    }
}
int my_keyhook(int keycode, t_data* data)
{
	if (keycode == XK_Escape){
        mlx_destroy_window(data->mlx, data->win);
        exit (0);
    }

    if (keycode == XK_i){
        if (data->xmax - data->xmin > 0.0000000000000000001){
            data->xmin += (data->xmax - data->xmin) * 0.1;
            data->xmax -= (data->xmax - data->xmin) * 0.1;
            data->ymin += (data->ymax - data->ymin) * 0.1;
            data->ymax -= (data->ymax - data->ymin) * 0.1;
        
            double zoom_level = 4.0 / (data->xmax - data->xmin);
            data->maxiter = (int)(50 * (1.0 + log10(zoom_level)));
            if (data->maxiter > 2000)
                data->maxiter = 2000;
        }
    }
    if (keycode == XK_o){
        data->xmin -= (data->xmax - data->xmin) * 0.1;
        data->xmax += (data->xmax - data->xmin) * 0.1;
        data->ymin -= (data->ymax - data->ymin) * 0.1;
        data->ymax += (data->ymax - data->ymin) * 0.1;
    }


    if (keycode == XK_w){
        data->ymin += (data->xmax - data->xmin) * 0.1;
        data->ymax += (data->ymax - data->ymin) * 0.1;
    }

    if (keycode == XK_a){
        data->xmin -= (data->xmax - data->xmin) * 0.1;
        data->xmax -= (data->ymax - data->ymin) * 0.1;

    }

    if (keycode == XK_s){
        data->ymin -= (data->xmax - data->xmin) * 0.1;
        data->ymax -= (data->ymax - data->ymin) * 0.1;
    }


    if (keycode == XK_d){
        data->xmin += (data->xmax - data->xmin) * 0.1;
        data->xmax += (data->ymax - data->ymin) * 0.1;
    }

    

    draw(data);
    return (0);    
}

int my_mouse_hook(int button, int x, int y, t_data *data)
{
    (void)x;
    (void)y;

    if (button == 4){
        if (data->xmax - data->xmin > 0.1)
        {
            data->xmin++;
            data->xmax--;
            data->ymin++;
            data->ymax--;
        }
    }
    else{
        data->xmin--;
        data->xmax++;
        data->ymin--;
        data->ymax++;
    }
    draw(data);
    return (0);
}

int main (){

    t_data data;
    
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
    

    draw(&data);
    mlx_hook(data.win, 02, 1L <<0, &my_keyhook, &data);
    mlx_hook(data.win, 04, 1L <<2, &my_mouse_hook, &data);

    mlx_loop(data.mlx);
    return (0);

}