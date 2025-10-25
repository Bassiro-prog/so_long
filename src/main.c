/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:41:28 by bnanque           #+#    #+#             */
/*   Updated: 2025/10/23 16:41:28 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_error("Usage: ./so_long <map.ber>");
	parse_map(&game, argv[1]);
	check_map(&game);
	init_game(&game);
	return (0);
}
