/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidruon <nidruon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:46:58 by nidruon           #+#    #+#             */
/*   Updated: 2024/12/17 13:47:20 by nidruon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/ft_printf/ft_printf.h"
# include "../libs/libft/libft.h"
# include "../libs/minilibx/mlx.h"

# define W_WIDTH 1000
# define W_HEIGHT 1000

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
}	t_game;


void	init_game(t_game *game);
void	main_window(t_game *game);
void	init_gfx(t_game *game);

#endif
