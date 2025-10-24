/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:59:39 by bnanque           #+#    #+#             */
/*   Updated: 2025/10/17 18:59:39 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	expose_handler(void *param)
{
	render_map((t_game *)param);
	return (0);
}

int	count_collectibles(char **map)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	init_game_state(t_game *game)
{
	game->moves = 0;
	game->collected = 0;
	game->collectibles = count_collectibles(game->map);
}

int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error("Failed to initialize MLX");
	game->win = mlx_new_window(game->mlx,
			game->width * TILE_SIZE,
			game->height * TILE_SIZE,
			"So Long");
	if (!game->win)
		exit_error("Failed to create window");
	init_game_state(game);
	load_images(game);
	mlx_expose_hook(game->win, expose_handler, game);
	mlx_hook(game->win, 2, 1L << 0, handle_input, game);
	mlx_hook(game->win, 17, 0, clean_game, game);
	mlx_loop(game->mlx);
	return (0);
}
