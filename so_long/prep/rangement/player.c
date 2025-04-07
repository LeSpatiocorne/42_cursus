/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:27:25 by nidruon           #+#    #+#             */
/*   Updated: 2025/02/06 17:14:59 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_player(t_game *game)
{
	int	img_width;
	int	img_height;

	game->player_img = mlx_xpm_file_to_image(game->mlx,
			"./assets/player.xpm", &img_width, &img_height);
	if (!game->player_img)
		return (0);
	return (1);
}

void	draw_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->player_img,
		game->player_x * game->tile_size,
		(game->player_y * game->tile_size) + 40);
}

int	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] != '1')
	{
		if (game->map[new_y][new_x] == 'C')
			game->collected++;
		if (game->map[new_y][new_x] == 'E')
		{
			if (game->collected == game->collectibles)
			{
				mlx_string_put(game->mlx, game->win, 
					(game->map_width * game->tile_size) / 2 - 50,
					(game->map_height * game->tile_size) / 2,
					0xFFFFFF, "YOU WIN!");
				mlx_do_sync(game->mlx);
				usleep(1000000);
			}
			else
			{
				mlx_string_put(game->mlx, game->win,
					(game->map_width * game->tile_size) / 2 - 100,
					(game->map_height * game->tile_size) / 2,
					0xFF0000, "Collect all coins first!");
				mlx_do_sync(game->mlx);
				return (0);
			}
		}
		game->map[game->player_y][game->player_x] = '0';
		game->player_x = new_x;
		game->player_y = new_y;
		game->map[new_y][new_x] = 'P';
		game->moves++;
		draw_map(game);
		return (1);
	}
	return (0);
}
