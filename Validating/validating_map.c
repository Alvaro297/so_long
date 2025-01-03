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

bool	ft_validation_map(char	*map_src, int fd, t_map *map)
{
	ft_init_map(map);
	if (ft_strstr(map_src, ".ber") == NULL)
	{
		ft_printf("\033cError invalid map no .ber\n");
		return (false);
	}
	if (ft_bad_width(fd, map) == true)
	{
		ft_printf("\033cError invalid width\n");
		return (false);
	}
	close(fd);
	fd = open(map_src, O_RDONLY);
	if (ft_bad_implementation(fd, map))
	{
		ft_printf("\033cError invalid map\n");
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}

int	ft_check_map_characters(char *line, t_map *map, int f)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] < 9 || line[i] > 13)
		{
			if ((f == 0 || f == map->height || i == 0
					|| i == map->width) && line[i] != '1')
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_map_items(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'E')
			map->n_exits++;
		else if (line[i] == 'C')
			map->n_collects++;
		else if (line[i] == 'P')
			map->n_players++;
		else if (line[i] == '1')
			map->n_wall++;
		else if (line[i] == 'V')
			map->n_villians++;
		else if (line[i] != '0' && line[i] != '\r' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}
