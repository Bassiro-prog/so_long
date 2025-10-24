/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:49:54 by bnanque           #+#    #+#             */
/*   Updated: 2025/10/20 17:49:54 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 64
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "../minilibx-linux/mlx.h"

/* ************************************************************************** */
/*                                STRUCTURES                                  */
/* ************************************************************************** */

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		player_count;
	int		exit_count;
	int		collectibles;
	int		collected;
	int		moves;
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_player;
	void	*img_player_up;
	void	*img_player_left;
	void	*img_player_right;
	void	*img_player_down;
	void	*img_collect;
	void	*img_exit;
	void	*img_floor;
	int		img_w;
	int		img_h;
}	t_game;

/* ************************************************************************** */
/*                               MAP FUNCTIONS                                */
/* ************************************************************************** */

int		parse_map(t_game *game, char *file);
void	read_map_lines(t_game *game, int fd);
int		check_map(t_game *game);
void	validate_map_element(t_game *game);
void	check_rectangular(t_game *game);
void	validate_wall_border(t_game *game);
void	validate_char(char c, t_game *game, int i, int j);
void	check_valid_path(t_game *game);
void	count_unreacheble(t_game *game, char **map,
			int *collect_f, int *exit_f);

/* ************************************************************************** */
/*                              GAME FUNCTIONS                                */
/* ************************************************************************** */

int		init_game(t_game *game);
void	load_images(t_game *game);
void	render_map(t_game *game);
int		handle_input(int keycode, void *param);
void	move_player(t_game *game, int dx, int dy);
int		clean_game_help(t_game *game);
int		process_tile(t_game *game, int x, int y);
void	*get_tile_image(t_game *game, char tile);

/* ************************************************************************** */
/*                              UTILS FUNCTIONS                               */
/* ************************************************************************** */

void	exit_error(char *msg);
void	free_map(char **map);
void	check_file_extension(char *filename);
char	**ft_realloc_map(char **old_map, char *new_line, int height);
int		clean_game(t_game *game);
#endif
