/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:52:43 by nidruon           #+#    #+#             */
/*   Updated: 2025/02/05 15:25:25 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_game(t_game *game)
{
	int	img_width;
	int	img_height;

	game->moves = 0;
	game->collected = 0;
	game->tile_size = 32;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, game->map_width * game->tile_size,
			(game->map_height * game->tile_size) + 40, "Maze O");
	if (!game->win)
	{
		free(game->mlx);
		return (0);
	}
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "./assets/brickwall.xpm",
			&img_width, &img_height);
	game->background_img = mlx_xpm_file_to_image(game->mlx,
			"./assets/background.xpm", &img_width, &img_height);
	if (!game->wall_img || !game->background_img)
	{
		mlx_destroy_window(game->mlx, game->win);
		free(game->mlx);
		return (0);
	}
	if (!init_player(game))
	{
		mlx_destroy_window(game->mlx, game->win);
		free(game->mlx);
		return (0);
	}
	if (!init_coin(game) || !init_exit(game))
	{
		mlx_destroy_window(game->mlx, game->win);
		free(game->mlx);
		return (0);
	}
	return (1);
}

int	handle_keypress(int keysym, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else if (keysym == XK_w || keysym == XK_Up)
		new_y--;
	else if (keysym == XK_s || keysym == XK_Down)
		new_y++;
	else if (keysym == XK_a || keysym == XK_Left)
		new_x--;
	else if (keysym == XK_d || keysym == XK_Right)
		new_x++;
	return (move_player(game, new_x, new_y));
}

void	main_window(t_game *game)
{
	if (!init_game(game))
		return ;
	draw_map(game);
	mlx_key_hook(game->win, handle_keypress, game);
	mlx_loop(game->mlx);
}
