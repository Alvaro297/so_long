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

static void	ft_lose_game(t_mlx *mlx)
{
	ft_printf("You lose! Try again!!!\n");
	ft_free_all(mlx);
	exit(0);
}

static void	ft_win_game(t_mlx *mlx)
{
	if (mlx->map.n_collects == 0)
	{
		ft_printf("You win!\n");
		ft_free_all(mlx);
		exit(0);
	}
}

void	ft_validate_win_lose_game(t_mlx *mlx)
{
	if (mlx->map.matriz[mlx->player.x][mlx->player.y] == 'E')
		ft_win_game(mlx);
	else if (mlx->map.matriz[mlx->player.x][mlx->player.y] == 'V')
		ft_lose_game(mlx);
}
