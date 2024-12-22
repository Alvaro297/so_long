/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 18:06:30 by alvamart          #+#    #+#             */
/*   Updated: 2024-12-10 18:06:30 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/so_long.h"

static void	ft_draw_background(t_mlx *mlx)
{
	int		i;
	int		j;
	int		img_width;
	int		img_height;
	void	*img_background;

	img_background = mlx_xpm_file_to_image(mlx -> mlx_ptr, GRASS_PATH,
			&img_width, &img_height);
	if (!img_background)
		return ;
	i = 0;
	while (mlx->height_win > i)
	{
		j = 0;
		while (mlx->width_win > j)
		{
			mlx_put_image_to_window(mlx -> mlx_ptr, mlx -> win_ptr,
				img_background, j, i);
			j += img_width;
		}
		i += img_height;
	}
	mlx_destroy_image(mlx->mlx_ptr, img_background);
}

static void	ft_draw_collections_player(t_mlx *mlx)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (mlx->map.n_collects > i)
	{
		x = mlx->map.collectibles[i].x * TILE_SIZE;
		y = mlx->map.collectibles[i].y * TILE_SIZE;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->map.collectibles[i++].img, y, x);
	}
	x = mlx->player.x * TILE_SIZE;
	y = mlx->player.y * TILE_SIZE;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->player.img_up, y, x);
	x = mlx->map.exit.height * TILE_SIZE;
	y = mlx->map.exit.width * TILE_SIZE;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->map.exit.img, y, x);
}

static void	ft_draw_wall(t_mlx *mlx)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (mlx->map.n_wall > i)
	{
		x = mlx->map.wall[i].height * TILE_SIZE;
		y = mlx->map.wall[i].width * TILE_SIZE;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->map.wall[i].img, y, x);
		i++;
	}
}

static void	ft_draw_villian(t_mlx *mlx)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	printf("Number of villains: %d\n", mlx->map.n_villians);
	while (mlx->map.n_villians > i)
	{
		x = mlx->map.villians[i].height * TILE_SIZE;
		y = mlx->map.villians[i].width * TILE_SIZE;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->map.villians[i].img, y, x);
		i++;
	}
}

void	ft_draw_images(t_mlx *mlx)
{
	ft_draw_background(mlx);
	ft_draw_wall(mlx);
	ft_draw_collections_player(mlx);
	ft_draw_villian(mlx);
}
