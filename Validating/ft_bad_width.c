/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bad_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-27 17:45:21 by alvamart          #+#    #+#             */
/*   Updated: 2024-12-27 17:45:21 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Headers/so_long.h"

static bool	ft_bad_width_help(t_map *map)
{
	if ((map->height == 0 || map->width == 0))
		return (true);
	map->height--;
	return (false);
}

bool	ft_bad_width(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd, 1);
	if (line != NULL)
	{
		map->width = ft_strlen_mod(line);
		map->height++;
		while (line != NULL)
		{
			free(line);
			line = get_next_line(fd, 1);
			map->height++;
			if (line != NULL && map->width != ft_strlen_mod(line))
			{
				free(line);
				get_next_line(fd, 0);
				return (true);
			}
		}
	}
	free(line);
	ft_bad_width_help(map);
	return (false);
}
