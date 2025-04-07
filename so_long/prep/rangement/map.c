/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:41:13 by nidruon           #+#    #+#             */
/*   Updated: 2025/02/06 16:20:21 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_map_chars(char c, t_game *game, int i, int j)
{
	if (c == 'P')
	{
		game->player_count++;
		game->player_x = j;
		game->player_y = i;
	}
	else if (c == 'E')
		game->exit_count++;
	else if (c == 'C')
		game->collectibles++;
	else if (c != '0' && c != '1')
		return (0);
	return (1);
}

static int	validate_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (!check_map_chars(game->map[i][j], game, i, j))
				return (0);
			if (i == 0 || i == game->map_height - 1)
				if (game->map[i][j] != '1')
					return (0);
			if (j == 0 || j == game->map_width - 1)
				if (game->map[i][j] != '1')
					return (0);
			j++;
		}
		i++;
	}
	return (game->player_count == 1 && game->exit_count == 1
		&& game->collectibles >= 1);
}

static int	get_map_dimensions(char *file, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	game->map_height = 0;
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	game->map_width = ft_strlen(line);
	if (line[game->map_width - 1] == '\n')
		game->map_width--;
	while (line)
	{
		game->map_height++;
		if (line[ft_strlen(line) - 1] == '\n')
		{
			if ((int)ft_strlen(line) - 1 != game->map_width)
			{
				free(line);
				return (0);
			}
		}
		else if ((int)ft_strlen(line) != game->map_width)
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), 1);
}

int	load_map(char *file, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	game->player_count = 0;
	game->exit_count = 0;
	game->collectibles = 0;
	if (!get_map_dimensions(file, game))
		return (0);
	game->map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(game->map);
		return (0);
	}
	i = 0;
	while (i < game->map_height && (line = get_next_line(fd)))
	{
		game->map[i] = ft_strdup(line);
		if (!game->map[i])
		{
			while (--i >= 0)
				free(game->map[i]);
			free(game->map);
			free(line);
			close(fd);
			return (0);
		}
		if (line[ft_strlen(line) - 1] == '\n')
			game->map[i][ft_strlen(line) - 1] = '\0';
		free(line);
		i++;
	}
	game->map[i] = NULL;
	close(fd);
	return (validate_map(game));
}

void	draw_map(t_game *game)
{
	int		y;
	int		x;
	char	*moves_str;
	char	*collect_str;

	mlx_clear_window(game->mlx, game->win);
	moves_str = ft_itoa(game->moves);
	collect_str = ft_itoa(game->collected);
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->mlx, game->win, 70, 20, 0xFFFFFF, moves_str);
	mlx_string_put(game->mlx, game->win, 120, 20, 0xbda53c, "coins : ");
	mlx_string_put(game->mlx, game->win, 200, 20, 0xbda53c, collect_str);
	free(moves_str);
	free(collect_str);
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->wall_img, x * game->tile_size,
					(y * game->tile_size) + 40);
			else
				mlx_put_image_to_window(game->mlx, game->win,
					game->background_img, x * game->tile_size,
					(y * game->tile_size) + 40);
			if (game->map[y][x] == 'E')
				draw_exit(game, x, y);
			else if (game->map[y][x] == 'C')
				draw_coin(game, x, y);
			x++;
		}
		y++;
	}
	draw_player(game);
}
