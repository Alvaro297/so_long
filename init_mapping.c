/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mapping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 18:12:21 by alvamart          #+#    #+#             */
/*   Updated: 2024-12-10 18:12:21 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/so_long.h"

void	ft_player_start(t_mlx *mlx)
{
	int			img_width;
	int			img_height;

	mlx->player.img_up = mlx_xpm_file_to_image(mlx->mlx_ptr,
			PLAYER_UP, &img_width, &img_height);
	mlx->player.img_down = mlx_xpm_file_to_image(mlx->mlx_ptr,
			PLAYER_DOWN, &img_width, &img_height);
	mlx->player.img_left = mlx_xpm_file_to_image(mlx->mlx_ptr,
			PLAYER_LEFT, &img_width, &img_height);
	mlx->player.img_right = mlx_xpm_file_to_image(mlx->mlx_ptr,
			PLAYER_RIGHT, &img_width, &img_height);
	ft_localization(mlx, &mlx->player);
}

static void	ft_localization_collec(t_mlx *mlx,
	t_collectible *collec, int x, int y)
{
	int		img_height;
	int		img_width;
	int		index;
	void	*collectible_img;

	index = 0;
	collectible_img = mlx_xpm_file_to_image(mlx->mlx_ptr, COLLEC_PATH,
			&img_width, &img_height);
	while (mlx->map.matriz[x])
	{
		y = 0;
		while (mlx->map.matriz[x][y])
		{
			if (mlx->map.matriz[x][y] == 'C')
			{
				collec[index].x = x;
				collec[index].y = y;
				collec[index].img = collectible_img;
				index++;
			}
			y++;
		}
		x++;
	}
}

void	ft_collec_start(t_mlx *mlx, t_map *map)
{
	t_collectible	*collectibles;

	collectibles = malloc(sizeof(t_collectible) * map->n_collects);
	if (!collectibles)
	{
		perror("Error\nmalloc failed\n");
		ft_free_map(map);
		exit(1);
	}
	ft_localization_collec(mlx, collectibles, 0, 0);
	mlx->map.collectibles = collectibles;
}

void	ft_localization(t_mlx *mlx, t_player *player)
{
	int	x;
	int	y;

	x = 0;
	while (mlx->map.matriz[x])
	{
		y = 0;
		while (mlx->map.matriz[x][y])
		{
			if (mlx->map.matriz[x][y] == 'P')
			{
				player->x = x;
				player->y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	ft_init_all_map(t_mlx *mlx, t_map *map)
{
	mlx->map = *map;
	mlx->height_win = map->height * TILE_SIZE;
	mlx->width_win = map->width * TILE_SIZE;
	ft_exit_start(mlx, map);
	ft_collec_start(mlx, map);
	if (map->n_villians > 0)
		ft_villian_start(mlx, map);
	ft_wall_start(mlx, map);
	mlx->moves = 0;
}
