#include "../Headers/so_long.h"

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
/*
void ft_init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->height_win = 0;
	mlx->width_win = 0;
	mlx->moves = 0;
	mlx->map = 0;
	mlx->player = memset(mlx->player, 0, sizeof(t_player));
}*/

void	ft_init_mapping(int fd, t_map *map)
{
	int	i;

	map->matriz = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->matriz)
		return ;
	i = 0;
	while (get_next_line(fd) != NULL)
	{
		map->matriz[i] = get_next_line(fd);
		i++;
	}
	map->matriz[i] = NULL;
}