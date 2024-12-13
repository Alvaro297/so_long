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
	if (!ft_validation_map(argv[1], fd, map, mlx))
	{
		close(fd);
		exit (1);
	}
	ft_init_mapping(fd, map);
	if(!ft_flood_fill(mlx, map))
	{
		close(fd);
		exit(1);
	}
	ft_init_all_map(mlx, map);
	close(fd);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	map;

	ft_init_mlx(&mlx);
	ft_init(argv[1], &mlx, &map);
	ft_player_start(&mlx);
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		return ;
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.width_win,
			mlx.height_win, "so_long");
	ft_draw_images(&mlx);
	ft_render_map(&mlx);
	mlx_loop(mlx.mlx_ptr);
	perror("Error\nloop failed\n");
}
