/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:52:43 by nidruon           #+#    #+#             */
/*   Updated: 2024/12/17 13:47:24 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_gfx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, W_WIDTH, W_HEIGHT, "so_long");
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(1);
	}
}

void	init_game(t_game *game)
{
	init_gfx(game);
}

void	main_window(t_game *game)
{
	init_game(game);
}
