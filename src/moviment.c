/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:51:52 by bnanque           #+#    #+#             */
/*   Updated: 2025/10/23 17:52:47 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (!process_tile(game, new_x, new_y))
		return ;
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collected == game->collectibles)
		{
			ft_printf("🎉Congratulation you win!!\n");
			clean_game(game);
		}
		return ;
	}
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf("Moviment %d\n", game->moves);
	render_map(game);
}

int	process_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map[y][x];
	if (x < 0 || x >= game->width || y < 0 || y >= game->height)
		return (0);
	if (tile == '1')
		return (0);
	if (tile == 'C')
		game->collected++;
	return (1);
}

void	move_player_with_dir(t_game *game, int dx, int dy, void *direction_img)
{
	game->img_player = direction_img;
	move_player(game, dx, dy);
}

int	handle_input(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_ESC)
		clean_game(game);
	else if (keycode == KEY_W)
		move_player_with_dir(game, 0, -1, game->img_player_up);
	else if (keycode == KEY_S)
		move_player_with_dir(game, 0, 1, game->img_player_down);
	else if (keycode == KEY_A)
		move_player_with_dir(game, -1, 0, game->img_player_left);
	else if (keycode == KEY_D)
		move_player_with_dir(game, 1, 0, game->img_player_right);
	return (0);
}
