/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_villian_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-27 17:43:22 by alvamart          #+#    #+#             */
/*   Updated: 2024-12-27 17:43:22 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/so_long.h"

static void	ft_localization_villan(t_mlx *mlx,
	t_villians *villian, int x, int y)
{
	int		img_height;
	int		img_width;
	int		index;
	void	*villian_img;

	index = 0;
	villian_img = mlx_xpm_file_to_image(mlx->mlx_ptr, VILLIAN_PATH,
			&img_width, &img_height);
	while (mlx->map.matriz[x])
	{
		y = 0;
		while (mlx->map.matriz[x][y])
		{
			if (mlx->map.matriz[x][y] == 'V')
			{
				villian[index].height = x;
				villian[index].width = y;
				villian[index].img = villian_img;
				index++;
			}
			y++;
		}
		x++;
	}
}

void	ft_villian_start(t_mlx *mlx, t_map *map)
{
	t_villians	*villians;

	villians = malloc(sizeof(t_collectible) * map->n_villians);
	if (!villians)
	{
		perror("Error\nmalloc failed\n");
		ft_free_map(map);
		exit(1);
	}
	ft_localization_villan(mlx, villians, 0, 0);
	mlx->map.villians = villians;
}
