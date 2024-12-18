/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 18:04:03 by alvamart          #+#    #+#             */
/*   Updated: 2024-12-10 18:04:03 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/so_long.h"

void	ft_init(char *argv, t_mlx *mlx, t_map *map)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("\033cError invalid path\n");
		exit (1);
	}
	if (!ft_validation_map(argv, fd, map))
	{
		close(fd);
		exit (1);
	}
	close(fd);
	fd = open(argv, O_RDONLY);
	ft_init_mapping(fd, map);
	ft_init_all_map(mlx, map);
	ft_player_start(mlx);
	if (!ft_flood_fill(mlx, map))
	{
		close(fd);
		ft_free_map(&mlx->map);
		exit(1);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	map;

	argc = 1;
	ft_init_mlx(&mlx);
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		return (1);
	ft_init(argv[argc], &mlx, &map);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.width_win,
		mlx.height_win, "so_long");
	if (!mlx.win_ptr)
	{
		ft_printf("\033Error creating window\n");
		ft_cleanup(&mlx);
		return (1);
	}
	ft_draw_images(&mlx);
	ft_render_map(&mlx);
	mlx_loop(mlx.mlx_ptr);
	perror("\033Error\nloop failed\n");
	exit(1);
}
