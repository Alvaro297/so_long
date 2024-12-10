#include "../Headers/so_long.h"

void	ft_wall_start(t_map *map)
{
	t_wall	*wall;

	wall = malloc(sizeof(t_collectible) * map->n_collects);
	if (!wall)
	{
		perror("Error\nmalloc failed\n");
		exit(1);
	}
	ft_localization_wall(map, wall);
	map->wall = wall;
}