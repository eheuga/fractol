#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>     // pour write()
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <X11/keysym.h>

typedef struct s_data
{
    void    *mlx;
    void    *win;
    void    *image;
    double  x;
    double  y;
    double  xmin;
    double  xmax;
    double  ymin;
    double  ymax;
    double  height;
    double  lenght;
    double  maxiter;
    int     pixel_bits;
    int     line_bytes;
    int     endian;
    char    *buffer;
    double  cx;
    double  cy;
    char    *name;
}   t_data;

void draw(t_data *data);
int my_keyhook(int keycode, t_data* data);
int my_mouse_hook(int button, int x, int y, t_data *data);
int close_window (t_data *data);
int create_color (int r, int g, int b);
int     mandelbrot(double cx, double cy, int maxiter);
void    draw_mandelbrot(t_data *data);
int     julia(double zr, double zi, double cx, double cy, int maxiter);
void    draw_julia(t_data *data);
void    my_put_pixel(t_data *data, double x, double y, int color);
int     print_usage(void);
double  ft_atof(char *str);
#endif