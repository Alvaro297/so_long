/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-14 17:10:52 by alvamart          #+#    #+#             */
/*   Updated: 2024-12-14 17:10:52 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/so_long.h"

int	ft_exit_fail(t_mlx *mlx)
{
	ft_printf("\033cYou press escape or x\n");
	ft_free_all(mlx);
	exit(0);
	return (0);
}
