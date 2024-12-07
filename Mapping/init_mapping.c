#include "../Headers/so_long.h"

void ft_init_mapping(int fd, t_map *map)
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
