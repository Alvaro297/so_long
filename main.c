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

void	ft_init_mapping(int fd, t_map *map)
{
	int		i;
	char	*line;

	map->matriz = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->matriz)
		return ;
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->matriz[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map->matriz[i] = NULL;
}

void	ft_init(char *argv, t_mlx *mlx, t_map *map)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error invalid path\n");
		exit (1);
	}
	if (!ft_validation_map(argv[1], fd, map, mlx))
	{
		perror("Error invalid map\n");
		exit (1);
	}
	ft_init_mapping(fd, map);
	ft_collec_start(mlx, map);
	ft_wall_start(mlx, map);
	mlx->map = *map;
	mlx->height_win = map->height * TILE_SIZE;
	mlx->width_win = map->width * TILE_SIZE;
	mlx->moves = 0;
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
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.width_win,
			mlx.height_win, "so_long");
	ft_draw_images(&mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
