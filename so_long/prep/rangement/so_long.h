/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:46:58 by nidruon           #+#    #+#             */
/*   Updated: 2025/02/06 16:40:14 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/ft_printf/ft_printf.h"
# include "../libs/minilibx/opengl/mlx.h"
# include "../libs/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <time.h>

#ifdef __linux__
    #include <X11/keysym.h>
#else
    #define XK_Escape 53
    #define XK_w 13
    #define XK_a 0
    #define XK_s 1
    #define XK_d 2
    #define XK_Up 126
    #define XK_Down 125
    #define XK_Left 123
    #define XK_Right 124
#endif

typedef struct s_game
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_data;
	unsigned char	*img_data_addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				img_width;
	int				img_height;
	int				img_bits_per_pixel;
	int				img_line_length;
	int				img_size_line;
	int				img_endian;
	char			**map;
	int				map_width;
	int				map_height;
	int				player_count;
	int				exit_count;
	int				collectibles;
	int				window_width;
	int				window_height;
	int				player_x;
	int				player_y;
	int				moves;
	int				collected;
	void			*wall_img;
	void			*background_img;
	int				tile_size;
	int				scale;
	void			*player_img;
	void			*coin_img;
	void			*exit_img;
}	t_game;


void	main_window(t_game *game);
//void	init_gfx(t_game *game);
int		load_map(char *file, t_game *game);
void	draw_map(t_game *game);
int		init_game(t_game *game);
void	draw_player(t_game *game);
int		move_player(t_game *game, int new_x, int new_y);
int		init_player(t_game *game);
int		init_coin(t_game *game);
void	draw_coin(t_game *game, int x, int y);
int		init_exit(t_game *game);
void	draw_exit(t_game *game, int x, int y);

#endif
