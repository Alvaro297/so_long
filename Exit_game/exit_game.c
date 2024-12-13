#include "../Headers/so_long.h"

int		ft_exit_fail(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	ft_printf("\033cYou press escape or x \n");
	exit(0);
	return (0);
}

int		ft_exit_victory(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	ft_printf("\033cYOU WIN \n");
	exit(0);
	return (0);
}