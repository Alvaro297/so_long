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

#include "../Headers/so_long.h"

void	ft_player_start(t_mlx *mlx)
{
	int			img_width;
	int			img_height;
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
	{
		perror("Error\nmalloc failed\n");
		exit(1);
	}
	player->img_up = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"../Textures/Gojo.xpm", &img_width, &img_height);
	player->img_down = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"../Textures/Gojo_back.xpm",
			&img_width, &img_height);
	player->img_left = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"../Textures/Gojo_left.xpm",
			&img_width, &img_height);
	player->img_right = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"../Textures/Gojo_right.xpm",
			&img_width, &img_height);
	ft_localization(mlx, player);
	mlx->player = *player;
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
	ft_localization_collec(mlx, collectibles);
	map->collectibles = collectibles;
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

void	ft_localization_collec(t_mlx *mlx, t_collectible *collec)
{
	int		x;
	int		y;
	int		index;
	void	*collectible_img;

	x = 0;
	index = 0;
	collectible_img = mlx_xpm_file_to_image(mlx->mlx_ptr, COLLEC_PATH, (int *)32, (int *)32);
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

void	ft_init_all_map(t_mlx *mlx, t_map *map)
{
	ft_collec_start(mlx, map);
	ft_wall_start(mlx, map);
	mlx->map = *map;
	mlx->height_win = map->height * TILE_SIZE;
	mlx->width_win = map->width * TILE_SIZE;
	mlx->moves = 0;
}
