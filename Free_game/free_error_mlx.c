#include "../Headers/so_long.h"

void	ft_error_message(t_mlx *mlx, char *message)
{
	if (message)
		ft_printf("%s", message);
	if (&mlx->map)
		ft_free_map(&mlx->map);
	if (&mlx->player)
		ft_free_player(mlx, &mlx->player);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	exit(1);
}
