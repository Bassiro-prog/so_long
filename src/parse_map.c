/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:26:00 by bnanque           #+#    #+#             */
/*   Updated: 2025/10/20 15:26:00 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	parse_map(t_game *game, char *file)
{
	int	fd;

	game->map = NULL;
	check_file_extension(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error("Error opening the file. Check if the file exists.");
	read_map_lines(game, fd);
	close(fd);
	if (game->height > 0)
		game->width = ft_strlen(game->map[0]);
	else
		exit_error("Error: Map file is empty or invalid.");
	return (0);
}

void	validate_map_element(t_game *game)
{
	int	i;
	int	j;

	game->player_count = 0;
	game->exit_count = 0;
	game->collectibles = 0;
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			validate_char(game->map[i][j], game, i, j);
			j++;
		}
		i++;
	}
	if (game->player_count != 1 || game->exit_count != 1
		|| game->collectibles == 0)
	{
		ft_printf("The map must contain exactly one player,");
		exit_error(" at least one exit, and at least one collectible");
	}
}

void	check_rectangular(t_game *game)
{
	int	i;
	int	len_row;

	if (game->height < 3 || game->width < 3)
		exit_error("The map must have at least 3 rows and 3 columns.");
	i = 1;
	while (i < game->height)
	{
		len_row = ft_strlen(game->map[i]);
		if (len_row != game->width)
			exit_error("Map is not rectangular:rows have different lengths.");
		i++;
	}
}

void	validate_wall_border(t_game *game)
{
	int		i;
	int		j;
	char	current;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			current = game->map[i][j];
			if (i == 0 || i == game->height - 1
				|| j == 0 || j == game->width - 1)
			{
				if (current != '1')
					exit_error("The map is not surrounded by walls");
			}
		j++;
		}
		i++;
	}
}
