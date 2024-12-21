#include "Headers/so_long.h"

void	ft_exit_start(t_mlx *mlx, t_map *map)
{
	int			img_width;
	int			img_height;

	map->exit.img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			EXIT_PATH, &img_width, &img_height);
	map->exit.img_out = mlx_xpm_file_to_image(mlx->mlx_ptr,
			EXIT_OUT, &img_width, &img_height);
	ft_localization_exit(mlx, &mlx->map.exit);
	mlx->map.exit = map->exit;
}

void	ft_localization_exit(t_mlx *mlx, t_exit *exit)
{
	int	x;
	int	y;

	x = 0;
	while (mlx->map.matriz[x])
	{
		y = 0;
		while (mlx->map.matriz[x][y])
		{
			if (mlx->map.matriz[x][y] == 'E')
			{
				exit->height = x;
				exit->width = y;
				return ;
			}
			y++;
		}
		x++;
	}
}
