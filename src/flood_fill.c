/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:04:52 by bnanque           #+#    #+#             */
/*   Updated: 2025/10/17 14:04:52 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_fill(t_game *game, int x, int y, char fill_char)
{
	if (x < 0 || x >= game->width || y < 0 || y >= game->height)
		return ;
	if (game->map[y][x] == '1' || game->map[y][x] == fill_char)
		return ;
	game->map[y][x] = fill_char;
	flood_fill(game, x + 1, y, fill_char);
	flood_fill(game, x - 1, y, fill_char);
	flood_fill(game, x, y + 1, fill_char);
	flood_fill(game, x, y - 1, fill_char);
}

static char	**copy_map(char **map, int height)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (height + 1));
	if (!map_copy)
		exit_error("Memory allocation failed");
	i = 0;
	while (i < height)
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
		map_copy[height] = NULL;
	return (map_copy);
}

void	check_valid_path(t_game *game)
{
	char	**copy;
	int		collect_found;
	int		exit_found;
	char	**original_map;

	copy = copy_map(game->map, game->height);
	original_map = game->map;
	game->map = copy;
	flood_fill(game, game->player_x, game->player_y, 'F');
	count_unreacheble(game, copy, &collect_found, &exit_found);
	free_map(copy);
	game->map = original_map;
	if (collect_found > 0 || exit_found > 0)
		exit_error("Invalid: some collectibles or the exit are unreachable");
}

void	count_unreacheble(t_game *game, char **map, int *collect_f, int *exit_f)
{
	int	i;
	int	j;

	*collect_f = 0;
	*exit_f = 0;
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (map[i][j] == 'C')
				(*collect_f)++;
			if (map[i][j] == 'E')
				(*exit_f)++;
		j++;
		}
		i++;
	}
}
