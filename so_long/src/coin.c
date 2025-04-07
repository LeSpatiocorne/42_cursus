/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:27:25 by nidruon           #+#    #+#             */
/*   Updated: 2025/03/07 14:25:50 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_coin(t_game *game)
{
	int	img_width;
	int	img_height;

	game->coin_img = mlx_xpm_file_to_image(game->mlx,
			"./assets/coin.xpm", &img_width, &img_height);
	if (!game->coin_img)
		return (0);
	return (1);
}

void	draw_coin(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->coin_img,
		x * game->tile_size,
		(y * game->tile_size) + 40);
}
