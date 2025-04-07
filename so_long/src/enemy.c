/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:15:00 by nidruon           #+#    #+#             */
/*   Updated: 2025/03/07 14:39:21 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_enemy(t_game *game)
{
	int	img_width;
	int	img_height;

	game->enemy_img = mlx_xpm_file_to_image(game->mlx,
			"./assets/enemy.xpm", &img_width, &img_height);
	if (!game->enemy_img)
		return (0);
	return (1);
}

void	draw_enemy(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->enemy_img,
		x * game->tile_size,
		(y * game->tile_size) + 40);
}

int	is_valid_move(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map_width || y >= game->map_height)
		return (0);
	return (game->map[y][x] != '1');
}

void	add_move(int moves[4][2], int *count, int dx, int dy)
{
	moves[*count][0] = dx;
	moves[*count][1] = dy;
	(*count)++;
}

void	check_moves(t_game *game, int moves[4][2], int *count)
{
	int	dx;
	int	dy;
	int	move_x;
	int	move_y;

	dx = game->player_x - game->enemy_x;
	dy = game->player_y - game->enemy_y;
	if (rand() % 2)
	{
		if (is_valid_move(game, game->enemy_x + 1, game->enemy_y))
			add_move(moves, count, 1, 0);
		if (is_valid_move(game, game->enemy_x - 1, game->enemy_y))
			add_move(moves, count, -1, 0);
		if (is_valid_move(game, game->enemy_x, game->enemy_y + 1))
			add_move(moves, count, 0, 1);
		if (is_valid_move(game, game->enemy_x, game->enemy_y - 1))
			add_move(moves, count, 0, -1);
	}
	else
	{
		move_x = (dx > 0) * 1 + (dx < 0) * (-1);
		move_y = (dy > 0) * 1 + (dy < 0) * (-1);
		if (dx && is_valid_move(game, game->enemy_x + move_x, game->enemy_y))
			add_move(moves, count, move_x, 0);
		if (dy && is_valid_move(game, game->enemy_x, game->enemy_y + move_y))
			add_move(moves, count, 0, move_y);
	}
}

int	move_enemy(t_game *game)
{
	int	moves[4][2];
	int	count;
	int	new_x;
	int	new_y;
	int	choice;

	count = 0;
	check_moves(game, moves, &count);
	if (count > 0)
	{
		choice = rand() % count;
		new_x = game->enemy_x + moves[choice][0];
		new_y = game->enemy_y + moves[choice][1];
		game->map[game->enemy_y][game->enemy_x] = '0';
		game->map[new_y][new_x] = 'X';
		game->enemy_x = new_x;
		game->enemy_y = new_y;
		return (1);
	}
	return (0);
}
