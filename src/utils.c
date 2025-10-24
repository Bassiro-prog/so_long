/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:17:56 by bnanque           #+#    #+#             */
/*   Updated: 2025/10/20 15:17:56 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_error(char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write(2, &msg[i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit(1);
}

void	check_file_extension(char *filename)
{
	size_t	ext_len;
	int		len;
	int		i;

	len = 4;
	ext_len = ft_strlen(filename);
	if (ext_len < (size_t)len)
		exit_error("Name of the file is too short");
	i = (int)ext_len - len;
	if (ft_strncmp(&filename[i], ".ber", 4) != 0)
		exit_error("File extension invalid it should be .ber");
}

char	**ft_realloc_map(char **old_map, char *new_line, int height)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * (height + 2));
	if (!new_map)
		exit_error("Memory allocation failed");
	i = 0;
	while (i < height)
	{
		new_map[i] = old_map[i];
		i++;
	}
	new_map[i] = new_line;
	new_map[i + 1] = NULL;
	free(old_map);
	return (new_map);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
