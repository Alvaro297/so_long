#include "../Headers/so_long.h"

void	ft_draw_background(t_mlx *mlx)
{
	int		i;
	int		j;
	int		img_width;
	int		img_height;
	void	*img_background;

	img_background = mlx_xpm_file_to_image(mlx -> mlx_ptr, GRASS_PATH, &img_width, &img_height);
	i = 0;
	while (mlx->height_win > i)
	{
		j = 0;
		while (mlx->width_win > j)
		{
			mlx_put_image_to_window(mlx -> mlx_ptr, mlx -> win_ptr, img_background, i, j);
			j += img_width;
		}
		i += img_width;
	}
}

void	ft_draw_collections(t_mlx *mlx)
{
	int		i;
	int		j;
	int		img_width;
	int		img_height;

	i = 0;
	while (mlx->map.n_collects > i)
	{
		mlx->map.collectibles[i].x * 32;
		mlx->map.collectibles[i].y * 32;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->map.collectibles[i].img,
				mlx->map.collectibles[i].x * 32, mlx->map.collectibles[i].y * 32);
	}
}

void	ft_draw_images(t_mlx *mlx)
{
	ft_draw_background(mlx);
	ft_draw_collections(mlx);
}
