#include <mlx.h>

typedef struct s_data{
    void *mlx;
    void *win;
    int x;
    int y;
}   t_data;


int create_color (int r, int g, int b){
    return (r << 16 | g << 8 | b);
}
int main (){

    t_data data;
    int color = create_color(10,255,40);

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 800, 800, "test");
    
    data.x = 0;
    data.y = 0;
    

    while (data.x < 800){
        
        data.y = 0;
        while (data.y < 800){

            mlx_pixel_put(data.mlx, data.win, data.x, data.y, color);
            data.y++;
        }
        mlx_pixel_put(data.mlx, data.win, data.x, data.y, color);
        data.x++;
    }
    mlx_loop(data.mlx);
    return (0);

}