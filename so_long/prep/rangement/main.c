/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:51:49 by nidruon           #+#    #+#             */
/*   Updated: 2025/02/06 16:20:27 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int     i;

	if (argc != 2)
	{
		ft_printf("Error\nUsage: %s <map.ber>\n", argv[0]);
		return (1);
	}
	ft_memset(&game, 0, sizeof(t_game));
	if (!load_map(argv[1], &game))
	{
		ft_printf("Error\nInvalid map\n");
		return (1);
	}
	game.window_width = game.map_width * 32;
	game.window_height = game.map_height * 32;

	main_window(&game);
	
	if (game.map)
	{
		i = 0;
		while (i < game.map_height)
			free(game.map[i++]);
		free(game.map);
	}

	return (0);
}
