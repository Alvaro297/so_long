#include "../Headers/so_long.h"

static bool	ft_bad_implemetation_help(int fd, t_map *map)
{
	
	if (map->n_exits != 1 || map->n_players != 1 || map->n_collects < 1)
	{
		get_next_line(fd, 0);
		return (true);
	}
	return (false);
}

bool	ft_bad_implementation(int fd, t_map *map)
{
	char	*line;
	int		f;

	f = 0;
	line = get_next_line(fd, 1);
	while (line != NULL)
	{
		if (ft_check_map_characters(line, map, f) == 1)
		{
			free(line);
			get_next_line(fd, 0);
			return (true);
		}
		if (ft_check_map_items(line, map) == 1)
		{
			free(line);
			get_next_line(fd, 0);
			return (true);
		}
		free(line);
		line = get_next_line(fd, 1);
		f++;
	}
	free(line);
	return (ft_bad_implemetation_help(fd, map));
}
