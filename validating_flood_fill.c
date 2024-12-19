/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating_flood_fill.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-14 17:08:39 by alvamart          #+#    #+#             */
/*   Updated: 2024-12-14 17:08:39 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/so_long.h"

static bool	validate_flood_fill(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] != '1' && tab[i][j] != 'E' && tab[i][j] != '\r'
				&& tab[i][j] != '\n')
			{
				ft_printf("Invalid character found at i = %d, j = %d, char = %i\n", i, j, tab[i][j]);
				return (false);
			}
			j++;
		}
		i++;

	}
	return (true);
}

static void	fill(char **tab, t_map_fill size, t_map_fill cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0
		|| cur.x >= size.x || tab[cur.x][cur.y] == '1'
		|| tab[cur.x][cur.y] == 'E')
		return ;
	tab[cur.x][cur.y] = '1';
	fill(tab, size, (t_map_fill){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_map_fill){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_map_fill){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_map_fill){cur.x, cur.y + 1}, to_fill);
}

static void	flood_fill(char **tab, t_map_fill size, t_map_fill begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

static char	**ft_matriz_copy(t_map *map)
{
	char **matriz_copy;
	int		i;

	i = 0;
	matriz_copy = (char **)malloc(sizeof(char *) * map->height);
	while (i < map -> height)
	{
		matriz_copy[i] = ft_strdup(map->matriz[i]);
		if (!matriz_copy[i])
		{
			ft_printf("Error: Memory allocation failed for matriz_copy[%d]\n", i);
			while (i-- > 0)
				free(matriz_copy[i]);
			free(matriz_copy);
			return (NULL);
		}
		i++;
	}
	matriz_copy[map->height] = NULL;
	return (matriz_copy);
}

bool	ft_flood_fill(t_mlx *mlx, t_map *map)
{
	char		**matriz_copy;
	t_map_fill	size;
	t_map_fill	begin;
	int			i;

	i = 0;
	size.x = map->height;
	size.y = map->width;
	begin.x = mlx->player.x;
	begin.y = mlx->player.y;
	matriz_copy = ft_matriz_copy(map);
	flood_fill(matriz_copy, size, begin);
	if (!validate_flood_fill(matriz_copy))
	{
		ft_printf("\033cError player cant go for all map\n");
		while (i < map->height)
			free(matriz_copy[i++]);
		free(matriz_copy);
		return (false);
	}
	while (i < map->height)
		free(matriz_copy[i++]);
	free(matriz_copy);
	return (true);
}
