/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 18:11:15 by alvamart          #+#    #+#             */
/*   Updated: 2024-12-10 18:11:15 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/so_long.h"

void	ft_init_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->img_up = NULL;
	player->img_down = NULL;
	player->img_left = NULL;
	player->img_right = NULL;
}

void	ft_init_map(t_map *map)
{
	map->matriz = NULL;
	map->height = 0;
	map->width = 0;
	map->n_collects = 0;
	map->n_players = 0;
	map->n_villians = 0;
	map->n_exits = 0;
	map->n_wall = 0;
	map->exit.height = 0;
	map->exit.width = 0;
	map->exit.img = NULL;
	map->exit.img_out = NULL;
	map->collectibles = NULL;
	map->villians = NULL;
	map->wall = NULL;
}

void	ft_init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->height_win = 0;
	mlx->width_win = 0;
	mlx->moves = 0;
	ft_init_map(&mlx->map);
	ft_init_player(&mlx->player);
}

void	ft_init_mapping(int fd, t_map *map)
{
	int		i;
	char	*line;
	char	*trimmed_line;

	map->matriz = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->matriz)
		return ;
	i = 0;
	line = get_next_line(fd, 1);
	while (line != NULL)
	{
		trimmed_line = ft_strtrim(line, "\n");
		free(line);
		map->matriz[i] = trimmed_line;
		line = get_next_line(fd, 1);
		i++;
	}
	map->matriz[i] = NULL;
}
