#include "../libs/minilibx/opengl/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
}   t_data;

int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    free(data->mlx);
    exit(0);
    return (0);
}

int key_hook(int keycode, t_data *data)
{
    if (keycode == 65307) // ESC key
        close_window(data);
    return (0);
}

int main(int argc, char **argv)
{
    t_data  data;
    int     width;
    int     height;

    if (argc != 2)
    {
        write(2, "Usage: ./program <xpm_file>\n", 28);
        return (1);
    }

    data.mlx = mlx_init();
    if (!data.mlx)
    {
        write(2, "Error: Failed to initialize MLX\n", 31);
        return (1);
    }

    data.img = mlx_xpm_file_to_image(data.mlx, argv[1], &width, &height);
    if (!data.img)
    {
        write(2, "Error: Failed to load XPM file '", 31);
        write(2, argv[1], strlen(argv[1]));
        write(2, "'\nPossible causes:\n- File doesn't exist\n- Not a valid XPM format\n- File permissions\n", 77);
        free(data.mlx);
        return (1);
    }

    data.win = mlx_new_window(data.mlx, width, height, "XPM Viewer");
    if (!data.win)
    {
        write(2, "Error: Failed to create window\n", 30);
        mlx_destroy_image(data.mlx, data.img);
        free(data.mlx);
        return (1);
    }

    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
    mlx_hook(data.win, 17, 0, close_window, &data);
    mlx_key_hook(data.win, key_hook, &data);
    mlx_loop(data.mlx);

    return (0);
}
/*
To compile this file : 
gcc asset_tester.c -Llibs/minilibx/opengl -lmlx -framework OpenGL -framework AppKit -o asset_tester
*/