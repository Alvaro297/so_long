/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-14 18:06:29 by alvamart          #+#    #+#             */
/*   Updated: 2024-12-14 18:06:29 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/so_long.h"

/*
void	ft_validate_lose_game(t_mlx *mlx, t_player player, int keycode)
{
	if (keycode == KEY_W && mlx->map.matriz[player.y + 1][player.x] == 'V')
		ft_lose_game(mlx);
	else if (keycode == KEY_S && mlx->map.matriz[player.y - 1][player.x] == 'V')
		ft_lose_game(mlx);
	else if (keycode == KEY_A && mlx->map.matriz[player.y][player.x + 1] == 'V')
		ft_lose_game(mlx);
	else if (keycode == KEY_D && mlx->map.matriz[player.y][player.x - 1] == 'V')
		ft_lose_game(mlx);
}*/

void	ft_validate_win_game(t_mlx *mlx, t_player player, int keycode)
{
	if (keycode == KEY_W && mlx->map.matriz[player.y + 1][player.x] == 'E')
		ft_win_game(mlx);
	else if (keycode == KEY_S && mlx->map.matriz[player.y - 1][player.x] == 'E')
		ft_win_game(mlx);
	else if (keycode == KEY_A && mlx->map.matriz[player.y][player.x + 1] == 'E')
		ft_win_game(mlx);
	else if (keycode == KEY_D && mlx->map.matriz[player.y][player.x - 1] == 'E')
		ft_win_game(mlx);
}
/*
void	ft_lose_game(t_mlx *mlx)
{
	ft_printf("You lose!\n");
	ft_free_all(mlx);
	exit(0);
}*/

void	ft_win_game(t_mlx *mlx)
{
	if (mlx->map.n_collects == 0)
	{
		ft_printf("You win!\n");
		ft_free_all(mlx);
		exit(0);
	}
}
