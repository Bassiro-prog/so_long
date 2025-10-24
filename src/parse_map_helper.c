/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:05:02 by bnanque           #+#    #+#             */
/*   Updated: 2025/10/20 17:42:11 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	validate_char(char c, t_game *game, int i, int j)
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
		exit_error("Invalid character in the map");
}

int	check_map(t_game *game)
{
	if (!game->map)
		exit_error("Map is empty");
	check_rectangular(game);
	validate_wall_border(game);
	validate_map_element(game);
	check_valid_path(game);
	return (0);
}

void	read_map_lines(t_game *game, int fd)
{
	char	*line;
	size_t	len;
	int		height;

	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
		{
			line[len - 1] = '\0';
			len--;
		}
		if (len == 0)
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		game->map = ft_realloc_map(game->map, line, height);
		height++;
		line = get_next_line(fd);
	}
	game->height = height;
}
