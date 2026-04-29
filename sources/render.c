#include "fractol.h"

void my_put_pixel(t_data *data, double x, double y, int color){

    int offset;

    offset = (y * data->line_bytes)  + ( x * 4);

    if (x >= 0 && x < data->lenght &&  y >= 0 && y < data->height){
        if (data->endian == 1)
        {
            data->buffer[offset + 0] = (color >> 24);
            data->buffer[offset + 1] = (color >> 16) & 0xFF;
            data->buffer[offset + 2] = (color >> 8) & 0xFF;
            data->buffer[offset + 3] = (color) & 0xFF;
        }
        else if (data->endian == 0)
        {
            data->buffer[offset + 0] = (color) & 0xFF;
            data->buffer[offset + 1] = (color >> 8) & 0xFF;
            data->buffer[offset + 2] = (color >> 16) & 0xFF;
            data->buffer[offset + 3] = (color >> 24);
        }

    }

}