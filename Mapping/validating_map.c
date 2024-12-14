/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 18:14:45 by alvamart          #+#    #+#             */
/*   Updated: 2024-12-10 18:14:45 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/so_long.h"

bool	ft_validation_map(char	*map_src, int fd, t_map *map, t_mlx *mlx)
{
	ft_init_map(map);
	if (ft_strstr(map_src, ".ber") == NULL)
	{
		ft_printf("\033cError invalid map\n");
		return (false);
	}
	if (ft_bad_width(fd, map))
	{
		ft_printf("\033cError invalid width\n");
		return (false);
	}
	if (ft_bad_implementation(fd, map))
	{
		ft_printf("\033cError invalid bad implemets of player,\
			exit or collects\n");
		return (false);
	}
	return (true);
}

bool	ft_bad_width(int fd, t_map *map)
{
	char	*line;
	int		line_length;

	line = get_next_line(fd);
	if (line != NULL)
	{
		map->width = ft_strlen_mod(line);
		map->height++;
		while (line != NULL)
		{
			line = get_next_line(fd);
			if (map->width != ft_strlen_mod(line))
				return (true);
			map->height++;
		}
		if (map->height == map->width)
			return (true);
	}
	if (map->height == 0 || map->width == 0)
		return (true);
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
		if (ft_check_map_characters(line, map, f) == 1)
			return (true);
		if (ft_check_map_items(line, map, f) == 1)
			return (true);
		line = get_next_line(fd);
		f++;
	}
	return (false);
}

int	ft_check_map_characters(char *line, t_map *map, int f)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (f == 0 || f == map -> height)
		{
			if (line[i] != '1')
				return (1);
		}
		else
		{
			if (i == 0 || i == map -> width)
			{
				if (line[i] != '1')
					return (1);
			}
		}
		i++;
	}
	return (0);
}

int	ft_check_map_items(char *line, t_map *map, int f)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'E' || line[i] == 'C'
			|| line[i] == 'P' || line[i] == '1')
		{
			if (line[i] == '1')
				map->n_wall++;
			if (line[i] == 'E')
				map->n_exits++;
			if (line[i] == 'C')
				map->n_collects++;
			if (line[i] == 'P')
				map->n_players++;
		}
		i++;
	}
	if (map->n_exits != 1 || map->n_players != 1 || map->n_collects < 1)
		return (1);
	return (0);
}
