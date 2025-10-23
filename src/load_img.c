/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:06:34 by bnanque           #+#    #+#             */
/*   Updated: 2025/10/17 21:06:34 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_images(t_game *game)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"assets/wall.xpm", &game->img_w, &game->img_h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"assets/floor.xpm", &game->img_w, &game->img_h);
	game->img_player_up = mlx_xpm_file_to_image(game->mlx,
			"assets/player_up.xpm", &game->img_w, &game->img_h);
	game->img_player_down = mlx_xpm_file_to_image(game->mlx,
			"assets/playerdown.xpm", &game->img_w, &game->img_h);
	game->img_player_left = mlx_xpm_file_to_image(game->mlx,
			"assets/player_left.xpm", &game->img_w, &game->img_h);
	game->img_player_right = mlx_xpm_file_to_image(game->mlx,
			"assets/player_right.xpm", &game->img_w, &game->img_h);
	game->img_collect = mlx_xpm_file_to_image(game->mlx,
			"assets/collect.xpm", &game->img_w, &game->img_h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"assets/exit.xpm", &game->img_w, &game->img_h);
			game->img_player = game->img_player_up;
	if (!game->img_wall || !game->img_floor
		|| !game->img_player_up || !game->img_player_down
		|| !game->img_player_left || !game->img_player_right
		|| !game->img_collect || !game->img_exit)
	{
		ft_printf("Failed to load one or more XPM assets in assets/");
		clean_game(game);
	}
}

void	render_map(t_game *game)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_floor,
				x * TILE_SIZE,
				y * TILE_SIZE);
			img = get_tile_image(game, game->map[y][x]);
			if (img)
				mlx_put_image_to_window(game->mlx, game->win,
					img, x * TILE_SIZE, y * TILE_SIZE);
					x++;
		}
		y++;
	}
}

void	*get_tile_image(t_game *game, char tile)
{
	if (tile == '1')
		return (game->img_wall);
	if (tile == 'P')
		return (game->img_player);
	if (tile == 'C')
		return (game->img_collect);
	if (tile == 'E')
		return (game->img_exit);
	return (NULL);
}
