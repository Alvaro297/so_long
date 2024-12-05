#include "../Headers/libft.h"
#include "../Headers/so_long.h"

bool	ft_validation_map(char	*map_src, int fd, t_map *map, t_mlx *mlx)
{
	init_map(map);
	if (ft_strstr(map_src, ".ber") == NULL)
		return (false);
	if (ft_bad_width(fd, map))
		return (false);
	if (ft_bad_implementation(fd, map))
		return (false);
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

bool	ft_bad_implemetation(int fd, t_map *map)
{
	char	*line;
	int		line_length;
	int		column;
	int		f;

	f = 0;
	line_length = 0;
	column = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_check_map_characters(line, map, f++);
		line = get_next_line(fd);
	}
	return (false);
}

void	ft_check_map_characters(char *line, t_map *map, int f)
{
	int	i;

	i = 0;
	while (line[i])
	{
		/* code */
	}
	
}