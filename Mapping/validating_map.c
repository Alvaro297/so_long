#include "../Headers/libft.h"
#include "../Headers/so_long.h"

bool	ft_validation_map(char	*map_src, int fd, t_map *map, t_mlx *mlx)
{
	if (ft_strstr(map_src, ".ber") == NULL)
		return (false);
	if (ft_bad_width(fd, map))
		return (false);
	if (ft_bad_implementation(fd, map))
	{
		/* code */
	}
	
	
}

bool	ft_bad_width(int fd, t_map *map)
{
	char	*line;
	int		line_length;

	line = get_next_line(fd);
	if (line != NULL)
	{
		map->width = ft_strlen_mod(line);
		map->height += 1;
		while (line != NULL)
		{
			line = get_next_line(fd);
			if (map->width != ft_strlen_mod(line))
				return (true);
			map->height += 1;
		}
	}
	return (false);
}
