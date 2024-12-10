#include "../Headers/so_long.h"

void	ft_init_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->img_up = NULL;
	player->img_down = NULL;
	player->img_left = NULL;
	player->img_right = NULL;
}

void	ft_init_map(t_map *map)
{
	map->matriz = NULL;
	map->height = 0;
	map->width = 0;
	map->n_collects = 0;
	map->n_players = 0;
	map->n_exits = 0;
	map->n_wall = 0;
	map->collectibles = NULL;
	map->wall = NULL;
}

void ft_init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->height_win = 0;
	mlx->width_win = 0;
	mlx->moves = 0;
	ft_init_map(&mlx->map);
	ft_init_player(&mlx->player);
}
