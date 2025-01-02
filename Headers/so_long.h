/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 18:08:22 by alvamart          #+#    #+#             */
/*   Updated: 2024-12-10 18:08:22 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx_mia/mlx.h"
# include "../libft/ft_printf_so_long/ft_printf.h"
# include "structure.h"
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define MAX_WIDTH 1920
# define MAX_HEIGHT 1080
# define ESC 65307
# define KY_UP 65362
# define KY_DOWN 65364
# define KY_LEFT 65361
# define KY_RIGHT 65363
# define KY_W 119
# define KY_A 97
# define KY_S 115
# define KY_D 100
# define TILE_SIZE 32
# define PLAYER_UP "./Textures/Gojo.xpm"
# define PLAYER_DOWN "./Textures/Gojo_back.xpm"
# define PLAYER_LEFT "./Textures/Gojo_left.xpm"
# define PLAYER_RIGHT "./Textures/Gojo_right.xpm"
# define GRASS_PATH "./Textures/Floor.xpm"
# define WALL_PATH "./Textures/Tree.xpm"
# define VILLIAN_PATH "./Textures/Geto.xpm"
# define EXIT_PATH "./Textures/exit.xpm"
# define EXIT_OUT "./Textures/exit_out.xpm"
# define COLLEC_PATH "./Textures/Coleccionable.xpm"

// ---- Main ---- //
int		main(int argc, char **argv);
void	ft_init(char *argv, t_mlx *mlx, t_map *map);
// ---- Mapping ---- //
void	ft_init_player(t_player *player);
void	ft_init_map(t_map *map);
void	ft_init_mlx(t_mlx *mlx);
void	ft_init_mapping(int fd, t_map *map);
// -- Init Mappìng -- //
void	ft_player_start(t_mlx *mlx);
void	ft_collec_start(t_mlx *mlx, t_map *map);
void	ft_localization(t_mlx *mlx, t_player *player);
void	ft_init_all_map(t_mlx *mlx, t_map *map);
// -- Draw Images -- //
void	ft_draw_images(t_mlx *mlx);
// -- Init Exit -- //
void	ft_exit_start(t_mlx *mlx, t_map *map);
// -- Init Villian --//
void	ft_villian_start(t_mlx *mlx, t_map *map);
// -- Init Wall -- //
void	ft_wall_start(t_mlx *mlx, t_map *map);
// -- Validating Flood Fill -- //
bool	ft_flood_fill(t_mlx *mlx, t_map *map);
// -- Validating Map -- //
bool	ft_validation_map(char	*map_src, int fd, t_map *map);
bool	ft_bad_width(int fd, t_map *map);
bool	ft_bad_implementation(int fd, t_map *map);
int		ft_check_map_characters(char *line, t_map *map, int f);
int		ft_check_map_items(char *line, t_map *map);
// ---- Rendering ---- //
void	ft_render_map(t_mlx *mlx);
int		key_hook(int keycode, t_mlx *mlx);
void	ft_move(t_mlx *mlx, t_player player, int key, void *img_background);
void	ft_change_player_texture(t_mlx *mlx, t_player player, int key);
void	ft_delete_collect(t_mlx *mlx);
// ---- Endgame ---- //
void	ft_validate_win_lose_game(t_mlx *mlx);
int		ft_exit_fail(t_mlx *mlx);
// ---- Free game ---- //
void	ft_free_all(t_mlx *mlx);
void	ft_free_map(t_map *map);
void	ft_free_player(t_mlx *mlx, t_player *player);
void	ft_error_message(t_mlx *mlx, char *message);
#endif