#include "../Headers/so_long.h"

void	ft_cleanup(t_mlx *mlx)
{
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
		mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	ft_free_map(&mlx->map);
	ft_free_player(&mlx->player);
}
