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

#include "../Headers/so_long.h"

static bool	validate_flood_fill(char **tab)
{
	int		i;
	int		j;

	while (tab[i])
	{
		while (tab[i][j])
		{
			if (tab[i][j] != '1' && tab[i][j] != 'E')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static void	fill(char **tab, t_map_fill size, t_map_fill cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0
		|| cur.x >= size.x || tab[cur.y][cur.x] == '1'
		|| tab[cur.y][cur.x] == 'E')
		return ;
	tab[cur.y][cur.x] = '1';
	fill(tab, size, (t_map_fill){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_map_fill){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_map_fill){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_map_fill){cur.x, cur.y + 1}, to_fill);
}

static void	flood_fill(char **tab, t_map_fill size, t_map_fill begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

bool	ft_flood_fill(t_mlx *mlx, t_map *map)
{
	char		**matriz_copy;
	t_map_fill	size;
	t_map_fill	begin;

	size.x = map->height;
	size.y = map->width;
	begin.x = mlx->player.x;
	begin.y = mlx->player.y;
	matriz_copy = map->matriz;
	flood_fill(matriz_copy, size, begin);
	if (!validate_flood_fill(matriz_copy))
	{
		ft_printf("\033cError player cant go for all map\n");
		free(matriz_copy);
		return (false);
	}
	free(matriz_copy);
	return (true);
}
